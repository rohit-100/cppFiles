for _ in range(int(input())):
    n,g,b = list(map(int,input().split()))
    if g>=b:
        print(n)
        continue
    ans = 0
    m = n
    n=(n+1)//2
    com = n//g
    if n%g != 0:
        print(max(m,com*(b+g)+n%g))
    else:
        print(max(m,com*(b+g)-b))
