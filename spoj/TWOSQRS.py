t = int(input().strip())

sqaures = [x*x for x in range(1000005)]
#for i in range(50):
#    print(sqaures[i])

#print(t)
for tess in range(t):
    n = int(input())
    ans = -1
    for x in sqaures:
        if x > n-x :
            break
        find = n-x
        low = 0
        high = 1000004
        while low <= high:
            mid = (low+high)//2
            if sqaures[mid] == find:
                ans = mid
                break
            elif sqaures[mid] > find:
                high = mid-1
            else:
                low = mid+1
        if ans != -1:
            break

    if ans == -1:
        print("No")
    else:
        print("Yes")



