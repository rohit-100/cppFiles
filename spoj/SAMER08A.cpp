#include<bits/stdc++.h>
using namespace std;

void dijkestra(vector<vector<pair<int,int> > >&graph,vector<int>& dist,int src){

    dist[src] = 0;
    priority_queue< pair<int,int>, vector<pair<int,int> > ,greater<pair<int,int> > > pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        if(dist[top.second] != top.first)continue;

        for(auto vv:graph[top.second]){
            int to = vv.first;
            int wt = vv.second;
            if(dist[to] > dist[top.second] + wt){
                dist[to] = dist[top.second] + wt;
                pq.push({dist[to],to});
            }
        }
    }
}



int main(){
    while(true){
        int n,m;
        cin>>n>>m;
        if(n==0 and m==0) return 0;
        int s,d;cin>>s>>d;
        vector<vector<pair<int,int> > > graph(n),rgraph(n),newgraph(n);
        vector<pair<pair<int,int> ,int > > edges;
        for(int i=0;i<m;i++){
            int x,y,wt;cin>>x>>y>>wt;
            graph[x].push_back({y,wt});
            rgraph[y].push_back({x,wt});
            edges.push_back({{x,y},wt});
        }

        vector<int>dist(n,INT_MAX),rdist(n,INT_MAX),newdist(n,INT_MAX);
        dijkestra(graph,dist,s);
        dijkestra(rgraph,rdist,d);
        //for(int val:dist)cout<<val<<" ";
        //cout<<endl;
        for(auto edge : edges){
            int from = edge.first.first;
            int to = edge.first.second;
            int wt = edge.second;
            if(dist[from] + wt + rdist[to] != dist[d])
                newgraph[from].push_back({to,wt});

        }
        dijkestra(newgraph,newdist,s);
        if(newdist[d] != INT_MAX){
            cout<<newdist[d]<<endl;
        }
        else cout<<"-1\n";

    }
}
