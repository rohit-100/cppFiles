#include<bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int> >& tree,vector<vector<int> >& visited,int ver,int par ,int taken){
    int ans = 0;
    if(visited[ver][taken] != -1)return visited[ver][taken];
    if(taken)ans = 1;
    for(int vv:tree[ver])if(vv != par){
        if(taken == 0)ans += dfs(tree,visited,vv,ver,1-taken);
        else ans += min(dfs(tree,visited,vv,ver,1-taken),dfs(tree,visited,vv,ver,taken));
    }
    return visited[ver][taken]=ans;
}
int count(vector<int>& color,int val){
    int ans = 0;
    for(int v:color){
        if(val == v)ans++;
    }
    return ans;
}
int main(){

    int n;cin>>n;
    vector<vector<int> > tree(n+1);
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    vector<vector<int> > visited(n+1,vector<int>(2,-1));
    cout<<min(dfs(tree,visited,1,-1,0),dfs(tree,visited,1,-1,1));

}
