from sys import stdin,stdout
take = lambda: list(map(int,stdin.readline().split()))

mod = 1000000007
def power(n,m):
    res = 1
    while m >0:
        if n&1:
            res = res*n%mod
        m>>=1
        n = n*n%mod
    return res


for _ in range(int(stdin.readline())):
    n,k, = take()
    ans = 0
    arr = take()
    i = 0
    j = 0
    while j<n:
        
        if arr[j] != 1:
            k-=1
        if k<0:
            while k<0:
                if arr[i] == 0:
                    k+=1
                i+=1
        ans = max(ans,j-i+1)
        j+=1
    print(ans)
            

