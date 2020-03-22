while True:
    n = int(input())
    if n==0:
        break
    line = list(input())
    for i in range(0,len(line),n):
        if (i//n)&1:
            line[i:i+n] = line[i+n-1:i-1:-1]
#     print(line)
    ans = ""
    for i in range(n):
        for j in range(i,len(line),n):
            ans += line[j]
    print(ans)
            
