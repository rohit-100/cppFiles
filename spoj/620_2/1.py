from sys import stdin,stdout
take = lambda: list(map(int,stdin.readline().split()))
for _ in range(int(input())):
    x,y,a,b, = take()
#     print(x,y,a,b)
    if (y-x)%(a+b) == 0:
        print((y-x)//(a+b))
    else:
        print("-1")
