n,w = tuple(map(int,input().split()))
arr = []
for i in range(n):
  arr.append(tuple(map(int,input().split())))

dp = [[-1]*(w+1)]*n
# print(dp)
def fun(n,W):
  print(str(n) + " "+ str(w))
#   global dp
  if n<0:
    return 0
#   if W ==0:
#     return 0
  
  if W<0:
    return -100000000000000
  if dp[n][W] != -1:
    return dp[n][W]
  dp[n][W] = max(arr[n][1]+fun(n-1,W-arr[n][0]),fun(n-1,W))
  return dp[n][W]
print(fun(n-1,w))

# print(dp)
