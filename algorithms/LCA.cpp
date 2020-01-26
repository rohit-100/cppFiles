

// this is the naive way to find the lca between any two nodes with complexity O(h)
//

const int N = 1000005;
int depth[N];
int parent[N];


void dfs(int ver,int par){
    parent[ver] = par;
    depth[ver] = depth[par] + 1;
    for(int vv:tree[ver])if(vv != par)dfs(vv,ver);
}

int lca(int u,int v){
    if(u == v)return u;
    if(depth[u] > depth[v]){
        swap(u,v);
    }
    v = parent[v];
    return lca(u,v);
}


void preprocess(){
    depth[0] = -1;
    parent[1] = 0;
    dfs(1,0); // ver,parent
}







// We can further optimize this code to find the lca in O(sqrt(h)) with sqrt decomposition
// we will break the tree in  block size of sqrt(h) and the assign a jump_parent value to each node which can be used for quick jump



int jump_parent[N];
int depth[N];
int parent[N];
int block_size;

int calcHeight(int ver,int par){
    int ans = 0;
    for(int vv:tree[ver])if(vv != par) ans = max(ans,calcHeight(vv,ver));
    return 1+ans;
}

void dfs(int ver,int par){
    parent[ver] = par;
    depth[ver] = depth[par] + 1;
    if(depth[ver] % block_size == 0)
        jump_parent[ver] = parent[ver];
    else 
        jump_parent[ver] = jump_parent[par];

    for(int vv:tree[ver])if(vv != par)dfs(vv,ver);
}

int lcaNaive(int u,int v){
    if(u == v)return u;
    if(depth[u] > depth[v]){
        swap(u,v);
    }
    v = parent[v];
    return lcaNaive(u,v);
}

int lcaJump(int u,int v){
    while(jump_parent[u] != jump_parent[v]){
        if(depth[u] > depth[v]) u = jump_parent[u];
        else v = jump_parent[v];
    }
    return lcaNaive(u,v);
}

void preprocess(){
    int height = calcHeight(1,0);   // (ver,parent)
    block_size = sqrt(height);
    depth[0] = -1;
    dfs(1,0);
}







