for _ in range(int(input())):
    n = int(input())
    arr1 = list(map(int,input().split()))
    arr2 = list(map(int,input().split()))
    
    arr1.sort()
    arr2.sort()
    #print(arr1)
    #print(arr2)
    ans = 0
    for a,b in zip(arr1,arr2):
        ans += min(a,b)
    print(ans)

