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

n = 1000006
hp = [i for i in range(n)]

def seive():
    hp[2] = 2
    for i in range(2,n):
        if hp[i] == i:
            for j in range(2*i,n,i):
                hp[j] = i


seive()
# print(hp[:20])
to = [0]*n
to[1] = 1
def eular():
    for i in range(2,n):
        num = i
        newnum = num//hp[i]
        if newnum % hp[num] == 0:
            to[num] = hp[num]*to[newnum]
        else:
            to[num] = (hp[num] - 1)*to[newnum]
eular()
for _ in range(int(input())):
    num, = take()
    print(to[num])

