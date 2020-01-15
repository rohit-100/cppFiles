#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;
struct edge{
    int to,from,wt;
};
vector<edge>edges;
bool comp( edge a,edge b){
    return a.wt < b.wt;
}

int find_par(int v,vector<int> &par){
    if(v != par[v])return par[v]=find_par(par[v],par);
    return v;
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        edges.clear();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int a,b,c;
            string faltu;
            cin>>faltu;
            int m;
            cin>>m;
            while(m-->0){
                cin>>b>>c;
                edges.push_back({i,b,c});
            }
        }
        
        /*for(edge e:edges){
            cout<<e.to<<" "<<e.from<<" "<<e.wt<<endl;
        }*/

        sort(edges.begin(),edges.end(),comp);
        
        
        unsigned int ans=0;
        vector<int>par(n+1);
        
        for(int i=0;i<=n;i++) par[i]=i;
        
        for(edge e:edges){
          int   par_to = find_par(e.to,par);
           int   par_from = find_par(e.from,par);
            
            if(par_to != par_from ){
                ans += e.wt;
                par[par_to] = par_from;
            }
        }
        cout<<ans<<endl;
                
    }
}

