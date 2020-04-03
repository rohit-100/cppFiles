#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N = 200005;
vector<ll> tree[N];
ll ss[N];
ll ans[N];
void dfs(ll v,ll p){
    ss[v] = 1;
    for(ll vv : tree[v]){
        if(vv != p){
            dfs(vv,v);
            ss[v] += ss[vv];
        }
    }
    ans[v] += ss[v];
    for(ll vv:tree[v]){
        if(vv != p)ans[v] += ans[vv];
    }

}

void reroot(ll v,ll p){
    ss[v] -= ss[p];
    ans[v] -= ss[p];
    ans[v] -= ans[p];
    ss[p] += ss[v];
    ans[p] +=  ans[v];
    ans[p] += ss[v];
}
void dfs2(ll v,ll p,ll& val){
    for(ll vv:tree[v]){
        if(vv != p){
            reroot(v,vv);
            val = max(val,ans[vv]);
            dfs2(vv,v,val);
            reroot(vv,v);

        }
    }
}
int main(){
    
    ll n;cin>>n; 
    for(ll i=0;i<n-1;i++){
        ll x,y;cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    ll val = -1;
    dfs(1,1);
    val = ans[1];
//     for(ll i=1;i<=n;i++){
//         dfs(i,i);
//         for(ll i=1;i<=n;i++)cout<<ss[i]<<" ";
//         cout<<endl;
//         val = max(val,ans[i]);
//         for(ll j=0;j<=n;j++)ss[j]= 0,ans[j] =0;
//     }
    dfs2(1,1,val);
    cout<<val<<endl;
}
