n,k,s = list(map(int,input().split()))
n-=1
ans = []
if n*k < s or s<k:
    print("NO")
else:
    while k>0:
        low = 1
        high = n
        while low <= high:
            mid = (low + high)>>1
            if (k-1)*n >= s-mid and s-mid >= k-1:
                ans.append(mid)
                k-=1
                s-=mid
                break
            if s-mid > (k-1)*n:
                low = mid+1
            elif s-mid < k-1:
                high = mid-1
    print("YES")
    base = 1
    ans.sort(reverse = True)
    forward = True
    for val in ans:
        if forward:
            base+=val
            print(base,end=" ")
            forward = False
        else:
            base -= val
            print(base ,end= " ")
            forward = True

