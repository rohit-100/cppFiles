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
    n,m = list(map(int , input().split()))
    summ = n+m
    n = list(str(n))
    m = list(str(m))
    for i in range(len(n)):
        for j in range(len(m)):
            m[j],n[i] = n[i],m[j]
            summ = max(summ,int(str(n))+int(str(m)))
            m[j],n[i] = n[i],m[j]

    print(summ)
