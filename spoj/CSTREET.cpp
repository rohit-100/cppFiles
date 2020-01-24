#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int p;cin>>p;int n,m;cin>>n>>m;
        vector<vector<pair<int,int> > > g(n+1);
        for(int i=0;i<m;i++){
            int a,b,c;cin>>a>>b>>c;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        int cost = 0;
        vector<int>dist(n+1,INT_MAX);
        set<pair<int,int> > pq;
        pq.insert({0,1});
        //dist[1] = 0;
        vector<bool>done(n+1,false);
        
        while(!pq.empty()){
//            cout<<pq.size()<<endl;
            auto val = *pq.begin();
            pq.erase(pq.begin());
            if(done[val.second])continue;
            done[val.second] = true;
            cost += val.first;
            for(auto vv:g[val.second]){
                pq.insert({vv.second,vv.first});
            }
    }
        cout<<1ll*p*cost<<endl;
}
}
