from sys import stdin,stdout
take = lambda: list(map(int,stdin.readline().split()))
mod = 1000000007
def power(n,m):
    res = 1
    while m >0:
        if m&1:
            res = res*n%mod
        m>>=1
        n = n*n%mod
    return res


for _ in range(int(input())):
    n,k,= take()
    arr = take()
    total = sum(arr)
    val = total//k
    if(total % k ==0 and all(x<=val for x in arr)):
        print("YES")
    else:
        print("NO")
