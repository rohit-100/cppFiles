for _ in range(int(input())):
    n,x = list(map(int,input().split()))
    arr = list(map(int,input().split()))
    h = [0]*500
    for val in arr:
        h[val]+= 1
    ans = None
    for i in range(1,len(h)):
        val = h[i]
#         print(i,end = " ") 
        if val == 0:
            x -= 1
        else:
            continue
        if x < 0:
            ans = i-1
            break
    print(ans)
