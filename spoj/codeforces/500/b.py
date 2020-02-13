n,x = map(int,input().split())
arr = list(map(int,input().split()))
N = 100005
dp = [[False,False] for i in range(N)]
ans = 3
for val in arr:
    if dp[val][0]:
        ans = 0
    if dp[val][1]:
        ans = min(ans,1)
    temp = val
    val &=x
    if dp[val][1]:
        ans = min(ans,2)
    if dp[val][0]:
        ans = min(ans,1)
    dp[val][1] = True
    dp[temp][0]=True
    #for i in range(8):
    #    print(dp[i])
    #print()


if ans != 3:
    print(ans)
else:
    print("-1")
