#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int,int> > >& tree,vector<pair<int,int>& par,int ver,int parent,int dis){
    par[ver].first = parent;
    par[ver].second = dis;
    for(auto vv:tree[ver])if(vv.first != parent){
        dfs(tree,par,vv.first,ver,vv.second);
    }
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<vector<pair<int,int> > > tree(n+1);
        for(int i=1;i<n;i++){
            int x,y,z;cin>>x>>y>>z;
            tree[x].push_back({y,z});
            tree[y].push_back({x,z});
        }
        vector<pair<int,int> > par(n+1);
        dfs(tree,par,1,-1,0);

    }
}
