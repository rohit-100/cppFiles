n,m  = list(map(int,input().split()))
lens = list(map(int,input().split()))
total = sum(lens)
if total < n:
    print("-1")

else:
    lens = [(val,ind) for ind,val in enumerate(lens)]
    print(lens)
    lens.sort(reverse = True,key = lambda x:x[0])
    ans = []
    N = n
    rest = m
    total = 0
    for i in range(len(lens)):
        val  = lens[i][0]
        rest -= 1
        painted = min(val,n-rest)
#         print(painted,end=" ")
        total += painted
        n -= painted
        ans.append((painted,lens[i][1]))
    print(ans) 
#     ans.sort(reverse = True,key=lambda x:x[1])
    for tup in ans:
        print(N-tup[0]+1)
        N -= tup[0]

    

