#include<bits/stdc++.h>
using namespace std;
int dij(int src,int des,vector<vector<pair<int,int> > >& g){
    int n = g.size();
    vector<int>dis(n,INT_MAX);
    dis[src]=0;
    set<pair<int,int> > pq;
    pq.insert({0,src});
    while(!pq.empty()){
        auto it = *pq.begin();
        pq.erase(pq.begin());
        int nsrc = it.second;
        for(auto edge:g[nsrc]){
            int to = edge.first;
            int wt = edge.second;
            if(dis[nsrc] + wt < dis[to]){
                pq.erase({dis[to],to});
                dis[to]=dis[nsrc] + wt;
                pq.insert({dis[to],to});
            }
        }
    }
    return dis[des];
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        unordered_map<string,int>citimap;
        vector<vector<pair<int,int> > > g(n+1);
        for(int i=0;i<n;i++){
            string name ;
            cin>>name;
            citimap[name] = i+1;
            int m;
            cin>>m;
            for(int j=0;j<m;j++){
                int val,wt;
                cin>>val>>wt;
                g[i+1].push_back({val,wt});
                //g[val].push_back({i+1,wt});
            }

        }
        int q;
        cin>>q;

        while(q--){
            string src,dest;
            cin>>src>>dest;
            int a = citimap[src];
            int b = citimap[dest];
            cout<<dij(a,b,g)<<endl;
        }
    }
}
