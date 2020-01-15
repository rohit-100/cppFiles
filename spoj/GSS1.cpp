#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class node{
    public:
    ll ps,ss,ts,ans;
        node():ps(0),ss(0),ts(0),ans(0){}
        node(ll ts,ll ans):ts(ts),ans(ans),ps(ans),ss(ans){
          /*  if(ans < 0){
                ps = 0;
                ss = 0;
            }*/

        }
};
node merge(node a,node b){
    node ans(0,0);
    ans.ps = max(a.ps,a.ts+b.ps);
    ans.ss = max(b.ss,b.ts+a.ss);
    ans.ts = a.ts+b.ts;
    ans.ans= max(a.ans,max(b.ans,a.ss+b.ps));
    return ans;
}

void build(vector<node>& tree,vector<ll>& arr,ll c,ll s,ll e){
    if(s>e)return;
    if(s == e){
        tree[c] = node(arr[s],arr[s]);
        return ;
    }
    ll mid = (s+e)>>1;
    build(tree,arr,2*c+1,s,mid);
    build(tree,arr,2*c+2,mid+1,e);
    tree[c] = merge(tree[2*c+1],tree[2*c+2]);
    return;
}
ll get(vector<node>& tree,ll c,ll s,ll e,ll x,ll y){
    if(s>e or e<x or y<s)return -1e12;
    if(x<=s and e<=y)return tree[c].ans;
    ll mid = (s+e)>>1;
    return max(get(tree,2*c+1,s,mid,x,y),get(tree,2*c+2,mid+1,e,x,y));//tree[2*c+1].ss + tree[2*c+2].ps,g
}

void prll(vector<node>& tree){
    for(ll i=0;i<10;i++){
        cout<<tree[i].ps<<" "<<tree[i].ss<<" "<<tree[i].ts<<" "<<tree[i].ans<<endl;
    }
}

int main(){
    ll n;
    cin>>n;
    vector<ll>arr;
    vector<node>tree(4*n+44);
    for(ll i=0;i<n;i++){ll x;cin>>x;arr.push_back(x);}
    build(tree,arr,0,0,n-1);
    //prll(tree);
    ll m;
    cin>>m;
    while(m--){
        ll x,y;
        cin>>x>>y;
        x = max(1ll,x);
        y = min(y,n);
        assert(x<=y);
        cout<<get(tree,0,0,n-1,x-1,y-1)<<endl;
    }

}


