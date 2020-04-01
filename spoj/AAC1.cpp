#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        vector<vector<int> > g;
        int n,m;cin>>n>>m;
        g.resize(n+1);
        for(int i=0;i<m;i++){
            int x,y;cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int>dist(n+1,0);
        queue<int>q;
        q.push(1);
        while(!q.empty()){
            int val = q.front();
            q.pop();
            for(int vv:g[val]){
                if(!dist[vv]){
                    dist[vv] = dist[val]+1;
                    q.push(vv);
                }
            }
        }
        cout<<dist[n]<<endl;


    }
}
