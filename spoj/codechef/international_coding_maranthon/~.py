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


print(power(3,4))

