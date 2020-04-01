import math
# class edge:
#     def __init__(self,a,b,val):
#         self.a = a
#         self.b = b
#         self.val = val
# class edges:
#     def __init__(self,edge):

# giving wa


class kruskal:
    def __init__(self,n,m,edges):
        self.n = n
        self.m = m
        self.edges = edges
        self.par = [i for i in range(n+1)]
        self.ans = []
        self.dist = [0.0 for i in range(n+1)]
        self.tree = None
    def prepare(self):
        self.edges.sort(reverse = True,key = lambda x: x[2])
    def run(self):
        self.prepare()
        for edge in edges:
            a,b,val = edge
            if self.find_par(a) != self.find_par(b):
                self.ans.append(edge)
                par_a = self.find_par(a)
                par_b = self.find_par(b)
                self.par[par_a] = par_b
#         print(len(self.ans))
#         for edge in self.ans:
#             print(edge)
        self.tree = [ [] for i in range(n+1) ]
        for edge in self.ans:
            self.tree[edge[0]].append((edge[1],edge[2]))
            self.tree[edge[1]].append((edge[0],edge[2]))
        self.dfs(1,1,0.0)
        return math.exp(self.dist[n])


    def find_par(self,val):
        if self.par[val] == val:
            return val
        self.par[val] = self.find_par(self.par[val])
        return self.par[val]

    def dfs(self,val,par,wt):
        self.dist[val] = self.dist[par] + wt;
        for vv in self.tree[val]:
            if vv[0] != par:
                self.dfs(vv[0],val,vv[1])
while True:
    inp = input().split()
    if len(inp) < 2:
        break
    n,m = list(map(int,inp))
    edges = []
    for i in range(m):
        x,y,prob = list(map(int,input().split()))
        edges.append((x,y,math.log(prob/100)))
#     edges.sort(key = lambda x:x[2],reverse = True)
    
    solver = kruskal(n,m,edges)
    ans = solver.run()
    print(ans*100 + 0.000000001)
