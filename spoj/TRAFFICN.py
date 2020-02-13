loop = int(input().strip())
maxi = 1000000000005
import heapq
def dij(graph,dis,src):
    dis[src] = 0
    pq = []
    heapq.heappush(pq,(0,src))
    while len(pq) >0:
        dist,node = heapq.heappop(pq)
        if dist != dis[node]:
            continue
        for vertex in graph[node]:
            if dis[vertex[0]] > dis[node] + vertex[1]:
                dis[vertex[0]] = dis[node] + vertex[1]
                heapq.heappush(pq,(dis[vertex[0]],vertex[0]))




def print_graph(graph):
    for i in range(len(graph)):
        print("{}->>>>>>".format(i),end=" ")
        for val in graph[i]:
            print(val[0],val[1],end=" ")
        print()



while loop>0:
    loop = loop -1
    n,m,k,s,t = [int(x) for x in input().split()]
    graph = [[] for i in range(n+1)]
    revg = [[] for i in range(n+1)]
    for i in range(m):
        x,y,wt = [int(x) for x in input().split()]
        graph[x].append((y,wt))
        revg[y].append((x,wt))
    """print_graph(graph)
    print()
    print()
    print_graph(revg)"""
    ds = [maxi]*(n+1)
    dt = [maxi]*(n+1)

    dij(graph,ds,s)
    dij(revg,dt,t)

    ans = ds[t];
    while k>0:
        k = k-1
        x,y,wt = [int(x) for x in input().split()]
        ans = min(ans,ds[x]+wt+dt[y],ds[y]+wt+dt[x])
    if ans >= maxi:
        print("-1")
    else:
        print(ans)



