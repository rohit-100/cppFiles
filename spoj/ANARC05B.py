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

import bisect
while True:
    arr1 = take()
    arr2 = take()
    n = arr1[0]
    if n==0:
        break
    arr1 = arr1[1:]
    m = arr2[0]
    arr2 = arr2[1:]

    founded = []
    for ind,val in enumerate(arr1):
        foo = bisect.bisect_right(arr2,val)-1
        if arr2[foo] == val:
            founded.append((ind,foo))
    for i in range(1,n):
        arr1[i] += arr1[i-1]
    for i in range(1,m):
        arr2[i] += arr2[i-1]
    lasta = 0
    lastb = 0
    founded.append((n-1,m-1))
    ans = 0
    for val in founded:
        ans += max(arr1[val[0]]-lasta,arr2[val[1]]-lastb)
        lasta = arr1[val[0]]
        lastb = arr2[val[1]]
    print(ans)

