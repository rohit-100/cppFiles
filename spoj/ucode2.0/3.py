n,a,b = list(map(int,input().split()))
s = input()
ans = 0
prev = "x"
for ch in s:
    if ch == "x":
        prev = "x"
        continue
    if prev == "x":
        if a>0 and a>b:
            ans+=1
            a-=1
            prev = "a"
        elif b>0:
            b-=1
            ans+=1
            prev = "b"
    elif prev == "a":
        if b>0:
            b-=1
            ans+=1
            prev = "b"
    elif prev == "b":
        if a>0:
            a-=1
            ans+=1
            prev = "a"
print(ans)
