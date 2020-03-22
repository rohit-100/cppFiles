# from sys import stdin,stdout
# take = lambda: list(map(int,stdin.readline().split()))
# tests = lambda: for _ in range(int(stdin.readline()))

mod = 1000000007
def power(n,m):
    res = 1
    while m >0:
        if n&1:
            res = res*n%mod
        m>>=1
        n = n*n%mod
    return res


for _ in range(int(input())):
    n = int(input())
    
    arr = list(map(int,input().split()))
    if n<=5:
        arr.sort()
        print(sum(arr[-3:]))
        continue
    arr = arr[:] + arr[:] + arr[:]
#     print(arr)
    ans = -1
    for i in range(n,2*n):
        temp = arr[i-2:i+3]
        temp.sort()
        ans = max(ans,sum(temp[-3:]))
    print(ans)

