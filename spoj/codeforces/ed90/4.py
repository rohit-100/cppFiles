for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    diff = [0]*n
    odd = 0
    even = 0
    for ind,val in enumerate(arr):
        if ind % 2 == 0:
            even += val
        else:
            odd += val
        diff[ind] = even - odd
    premin = [0]*n
    premin[-1] = diff[-1]
    ind = [0]*n
    ind[-1]=n-1;
    if n>=2:
        premin[-2]= diff[-2]
        ind[-2] = n-2
    for i in range(n-3,-1,-1):
        if diff[i]  < premin[i+2]:
            premin[i] = diff[i]
            ind[i] = i
        else:
            premin[i] = premin[i+2]
            ind[i] = ind[i+2]
    ans = -1
    for i in range(n):
        temp = 0
        if i == 0:
            temp = 0
        else:
            temp -= diff[i-1]
        temp -= premin[i]
        temp += diff[-1]-diff[ind[i]]
        ans = max(ans,temp)
        print(ans)
#     print(ans)
    print(premin) 
    print(ind)
