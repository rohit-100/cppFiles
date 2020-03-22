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



for _ in range(int(input())):
    ss = input()
    if len(ss)>3 and ss[-4] == "1" and ss[-3] == "0" and ss[-2] == "0" and ss[-1] == "0":
        print("YES\n")
    else:
        print("NO")
        
