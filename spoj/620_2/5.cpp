#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >tree,up;
int hhh;
vector<int>ht,par,tout,tin;
int timer = 1;
void dfs(int ver,int pp){
    ht[ver] = 1+ht[pp];
    tin[ver] = ++timer;
    up[ver][0] = pp;
    for(int i=1;i<=hhh;i++){
        up[ver][i] = up[up[ver][i-1]][i-1];
    }
    for(int vv:tree[ver]){
        if(vv != pp){
            dfs(vv,ver);
        }
    }
    tout[ver] = ++timer;
}


bool is_ancestor(int u,int v){
    if(tin[u] <= tin[v] and tout[u] >= tout[v])return true;
    return false;
}
int lca(int u,int v){
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u))return v;
    for(int i = hhh;i>=0;i--){
        if(!is_ancestor(up[u][i] , v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}

int dist(int u,int v){
   int ancestor = lca(u,v);
   return ht[u] + ht[v] -2* ht[ancestor];
}
void print(vector<int>arr){
    for(int val:arr){
        cout<<val<<" ";
    }
    cout<<endl;

}
bool ok(int a,int b){
    return a<=b and a%2 == b%2;
}

int main(){

    int n;cin>>n;
    tree.resize(n+1);
    ht.resize(n+1,0);
    par.resize(n+1);
    tin.resize(n+1);
    tout.resize(n+1);
     hhh = ceil( log2(n));
    up.assign(n+1,vector<int>(hhh+1));
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1,1);
//     print(ht);
//     print(up[5]);    
    int q;cin>>q;
//     cout<<dist(2,5)<<endl;
    while(q--){
        int x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
//         cout<<lca(x,y)<<endl;
        int loop = dist(x,y) + 1;
        int distab = dist(a,b);
        int distxy = dist(x,y);
        int ax = dist(a,x);
        int ay = dist(a,y);
        int bx = dist(b,x);
        int by = dist(b,y);
        if(ok(distab,k) or ok(ax+by+1,k) or ok(ay+bx+1,k))
            cout<<"YES\n";
        else cout<<"NO\n";


}


}


// ax+1+by == k or ax+1+by+loop-1 == k or ay+1+bx == k or ay+loop-1+bx == k or 
