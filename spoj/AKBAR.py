tt = int(input().strip())
for ttt in range(tt):
    n,r,m = [int(x) for x in input().split()]
    graph  = [[] for i in range(n+1)]
    for i in range(r):
        x,y = [int(x) for x in input().split()]
        graph[x].append(y)
        graph[y].append(x)
    n+=1
    done=[False]*n

    ans = True
    for i in range(m):
        k,s = [int(x) for x in input().split()]
        stack = []
        stack.append((s,k))
        if done[s]:
            ans = False
        if ans is False :
            continue

        while len(stack)>0:
            last = stack.pop()
            done[last[0]] = True
            for to in graph[last[0]]:
                if last[1]>0:
                    if done[to]:
                        ans = False
                    else:
                        stack.append((to,last[1]-1))
    if not ans:
        print("Yes")
    else:
        print("No")



                    
