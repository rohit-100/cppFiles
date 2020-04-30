#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 300005;
vector<pair<ll,ll> >tree[N];
ll dp[N];
ll size[N];
void dfs(ll ver,ll par){
    dp[ver] = 0;
    size[ver] = 1;
    for(auto vv:tree[ver])if(vv.first  != par){
        dfs(vv.first ,ver);
        dp[ver] += dp[vv.first];
        dp[ver] += size[vv.first]*vv.second;
        size[ver] += size[vv.first];
    }


}
ll ans[N];
void change(int ver,int to,ll wt){

        size[ver] -= size[to];
        dp[ver] -= dp[to];
        dp[ver] -= size[to]*wt; 
        size[to] += size[ver];
        dp[to] += dp[ver];
        dp[to] += size[ver]*wt;
        ans[to]  = dp[to]; 
}
void dfs2(int ver,int par){
    for(auto vv:tree[ver])if(vv.first  != par){
        int to = vv.first;
        change(ver,to,vv.second);
        dfs2(to,ver);
        change(to,ver,vv.second);




    }
}
int main(){

    ll n;cin>>n;
    for(ll i=1;i<n;i++){
        ll u,v,w;cin>>u>>v>>w;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }
    dfs(1,-1);
    ans[1] = dp[1];
    dfs2(1,-1);
//     for(ll i=1;i<=n;i++){
//         dfs(i,-1,0);
//         cout<<dp[i]<<endl;
//         for(ll j=1;j<=n;j++){
// //             cout<<dp[j]<<" "<<size[j]<<" ,";
//             dp[j] = 0;
//             size[j] = 0; 
// 
//         }
// //         cout<<endl;
//     }
     for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
     cout<<endl;
}

