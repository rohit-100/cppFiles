for _ in range(int(input())):
    a = input()
    b = input()
    c = input()
    ans = True
    for aa,bb,cc in zip(a,b,c):
        if  aa==cc or cc ==bb:
            continue
        else:
            ans = False
    if ans:
        print("YES")
    else:
        print("NO")

