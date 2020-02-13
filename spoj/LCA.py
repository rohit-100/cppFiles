import math
tt = int(input().strip())
for ttt in range(tt):
    n = int(input().strip())
    tree = [[] for i in range(n+1)]
    for i in range(n):
        tree[i].append(input().split()[1:])
    tin = [0]*(n+1)
    tout = [0]*(n+1)
    l = math.ceil(math.log2(n))
    table = [[0 for i in range(l+1)] for i in range(n+1)]
    n = n+1
    timer = 1
    def dfs(v,p):
        tin[v] = timer
        timer += 1
        table[v][0] = p
        for i in range(1,l+1):
            table[v][i]=table[table[v][i-1]][i-1]
        for val in tree[v]:
            if val != p:
                dfs(val,v)
        tout[v] = timer
        timer += 1

    def is_ancestor(u,v):
        return tin[u] <= tin[v] and tout[u] >= tout[v]

    def get_ancestor(u,v):
        if is_ancestor(u,v):
            return u
        if is_ancestor(v,u):
            return v
        for i in range(l+1,-1,-1):
            if not is_ancestor(table[u][i],v):
                u = table[u][i]

        return table[u][0]
    dfs(1,1)
    q = int(input())
    print("Case {}:".format(ttt))
    for qq in range(q):
        u,v = [int(x) for x in input().split()]
        print(get_ancestor(u,v))







