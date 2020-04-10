import math
n = int(input())
arr = [int(x) for x in input().split()]

dp = [0]*n
for i in range(n):
    if i>=2:
        dp[i] = min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i-2]-arr[i]))
    elif i==1:
        dp[i] = abs(arr[i]-arr[i-1])
    else:
        dp[i] = 0
print(dp[n-1])
