k,n = list(map(int,input().split()))
arr = list(map(int,input().split()))
max_d = k-arr[-1] + arr[0]
for i in range(n-1):
  max_d = max(max_d,arr[i+1]-arr[i])
print(k-max_d)

