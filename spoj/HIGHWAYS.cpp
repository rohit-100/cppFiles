#include<bits/stdc++.h>
using namespace std;
#define inf 1000000008
const int N = 100005;
vector<pair<int,int> > graph[N];
int dist[N];
int n,m,start,last;
int main(){
   int t;
   cin>>t;
   while(t--){
       cin>>n>>m>>start>>last;
       for(int i=0;i<=n;i++)graph[i].clear();
       for(int i=0;i<m;i++){
           int x,y,wt;
           cin>>x>>y>>wt;
           graph[x].push_back({y,wt});
           graph[y].push_back({x,wt});


       }
       priority_queue<pair<int,int>,vector<pair<int,int> > , greater<pair<int,int> > > pq;
       pq.push({0,start});
       for(int i=0;i<=n;i++)dist[i] = inf;
       dist[start] = 0;
       
       while(!pq.empty()){
           auto top = pq.top();
           pq.pop();
           int d_v = top.first;
           int ver= top.second;
           if(dist[ver]  != d_v )continue;
        

           for(auto edge:graph[ver]){
               int to = edge.first;
               int wt = edge.second;
               if(dist[ver]+wt < dist[to]){
                    dist[to] = dist[ver] + wt;
                    pq.push({dist[to],to});
               }
           }


       }

//        cout<<endl;
       if(dist[last] == inf)cout<<"NONE\n";
       else cout<<dist[last]<<endl;
   }
     
}
