#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int>tree[N];
pair<int,int> sz[N];
int depth[N];
void dfs(int v,int p,int dep = 0){
    depth[v] = dep;
    for(int to:tree[v])if(to != p){
        dfs(to,v,dep+1);
        sz[v].first += sz[to].first;
    }
    sz[v].first++;
    sz[v].second = v;
}
bool is_tourism[N];
// long long dfs2(int v,int p,int depth = 0){
//     if(is_tourism[v] == false){
//         return 1ll*sz[v]*depth;
//     }
//     long long ans = 0;
//     for(int to:tree[v])if(to != p){
//         ans += dfs2(to,v,depth+1);
//     }
//     return ans;
// }
bool comp(pair<int,int> A,pair<int,int> B){
    int a = A.second;
    int b = B.second;
    return A.first!=B.first?A.first>B.first:depth[a]<depth[b];
}
int main(){

    int n,k;cin>>n>>k; 
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    for(int i=0;i<N;i++)is_tourism[i] = false;
    dfs(1,-1);
//     for(int i=1;i<=n;i++)cout<<sz[i]<<" ";
//     cout<<endl;
//     priority_queue<pair<int,pair<int,int> >> pq;
//     pq.push({sz[1],{1,-1}});
//     k = n-k;
//     while( k-->0 ){
//         auto tp = pq.top();
//         pq.pop();
//         is_tourism[tp.second.first] = true;
//         for(int to:tree[tp.second.first])if(to != tp.second.second)
//             pq.push({sz[to],{to,tp.second.first}});
//     }
//     cout<<dfs2(1,-1);

     sort(sz+1,sz+n+1,comp);
     for(int i=1;i<=n;i++){
         cout<<sz[i].first<<" "<<sz[i].second;
         cout<<endl;
     }
     long long ans = 0;
     for(int i=n-k+1;i<=n;i++){
        int ver = sz[i].second;
        ans += 1ll*depth[ver]*sz[i].first;
     }
     cout<<ans;
}
