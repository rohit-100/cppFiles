n= int(input())
arr = list(map(int,input().split()))
ans = 1
for i in range(n):
    temp = 1
    j = i-1
    left = arr[i]
    while j>=0 and arr[j] <= left:
        temp+=1
        left = arr[j]
        j-=1
    j = i+1
    right = arr[i]
    while j<n and right >= arr[j]:
        temp += 1
        right = arr[j]
        j+=1
    ans = max(ans,temp)
print(ans)
