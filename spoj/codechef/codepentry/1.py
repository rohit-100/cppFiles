t = int(input())
for _ in range(t):
    n,x = list(map(int, input().split()))
    side,lang = list(map(str,input().split()))
    if(side == "R"):
        x = n+1-x;
    print(x,end=" ")
    langs = [lang,"H" if lang == "E" else "E"]
    langs.reverse()
    print(langs[x%2])

    
