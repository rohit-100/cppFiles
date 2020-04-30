for _ in range(int(input())):
    t,n = list(map(int,input().split()))
    
    dp = [ [1 for x in range(10)] for i in range(n) ]
#     print(dp)
    for i in range(1,n):
        
        for j in range(10):
            dp[i][j] = 0
            for k in range(j+1):
                dp[i][j] += dp[i-1][k]
    print(t,sum(dp[n-1]))
