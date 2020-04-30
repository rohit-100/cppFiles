for _ in range(int(input())):
    n = int(input())
    arr = input()
    dp = [-1]*n
    def fun(i):
        if i>=n:
            return 0;
        if dp[i] != -1:
            return dp[i]
        ans = 0
        sweetness = 0
        for j in range(i,n):
            if arr[j]=="0":
                sweetness -= 1
            else:
                sweetness += 1

            if sweetness > 0:
                ans = max(ans,j-i+1+fun(j+1))
            else:
                ans = max(ans,fun(j+1))

        dp[i] = ans
        return ans
    
    
#     for i in range(n,-1,-1):
#         fun(i)
    fun(0)
#     print(dp)
    print(dp[0])
#     print(max(dp))
#     ans = 0;
#     i=0
#     while(i < n):
#         ans += dp[i]
#         if dp[i] == 0:
#             i+=1
#         else: 
#             i += dp[i]
#     print(ans)


