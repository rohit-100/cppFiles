for _ in range(int(input())):
    ss = input();
    arr = [0]*len(ss)
    val = 0
    ind = 0
    for ch in ss:
        if ch == '+':
            val += 1
        else:
            val -= 1
        arr[ind] = val
        ind += 1
    ans = 0
    mn = 0
#     print(arr)
    for ind,val in enumerate(arr):
        if val < mn:
            ans += ind+1
            mn = val
#             print(ans)
    ans += len(ss)
    print(ans)
               
