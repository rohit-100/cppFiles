def is_subsequence(text,pattern):
    n = len(text)
    m = len(pattern)
    dp = [[False for i in range(n+1)] for i in range(m+1)]
    dp[0][:] = [True]*(n+1)
    for i in range(1,m+1):
        for j in range(1,n+1):
            if text[j-1] == pattern[i-1]:
                dp[i][j] = dp[i-1][j-1] 
            else:
                dp[i][j] =  dp[i][j-1]
#     for val in dp:
#         print(val)
    return dp[m][n]

for _ in range(int(input())):
    s = input()
    t = input()
    ans = False
    n = len(s)
    m = len(t)
    for i in range(m//2+1):
        last = m-i
        print(t[:last]+ " " + t[last:])
        if is_subsequence(s,t[:last]) and is_subsequence(t[:last],t[last:]):
            ans = True
            break
        if ans:
            break
    if ans:
        print("YES")
    else:
        print("NO")

