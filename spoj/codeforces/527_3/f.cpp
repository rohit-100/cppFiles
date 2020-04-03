#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
#define ll long long 
vector<int> tree[N];
vector<int> wts;
ll cost[N],cumm[N],dist[N];
void dfs(int v,int p){
    cost[v] = wts[v];
    cumm[v] = wts[v];
    dist[v] = dist[p] + 1;
    for(int vv:tree[v]){
        if(vv != p){
            dfs(vv,v);
            cost[v] += cost[vv];
            cumm[v] += cumm[vv];
        }
    }
    

}
int main(){
    int n;cin>>n;
    wts.resize(n+1);
    for(int i=1;i<=n;i++)cin>>wts[i];
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++)cumm[i] -= wts[i];
    
     
}
