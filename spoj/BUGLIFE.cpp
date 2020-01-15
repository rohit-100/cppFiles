#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int> >& g,vector<int>& visited,int node,int start = 1){
    if(visited[node] != -1 and visited[node] != start )return false;
    if(visited[node] != -1 and visited[node] == start)return true;
    visited[node] = start;
    bool ans = true;
    for(int val:g[node]){
        bool temp =  dfs(g,visited,val,1-start);
        ans &= temp;
    }
    return ans;
}
    


int main(){
    int t;
    cin>>t;
    for(int e = 1;e<=t;e++){
        cout<<"Scenario #"<<e<<":\n";
        int n,m;
        cin>>n>>m;
        vector<vector<int> > g;
        g.resize(n+1);        
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        bool ans = true;
        vector<int> visited(n+1,-1);
        for(int node = 1;node <= n ;node++)if(visited[node] == -1){
            ans &= dfs(g,visited,node);
        }
        if(ans)
            cout<<"No suspicious bugs found!\n";
        else
            cout<<"Suspicious bugs found!\n";
    }



}

