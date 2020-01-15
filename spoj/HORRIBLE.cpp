#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 400005;

ll get( vector<ll>& tree,vector<ll>& lazy,ll s,ll ss,ll se,ll p,ll q);
void update(vector<ll>& tree,vector<ll>& lazy,ll s,ll ss,ll se,ll p,ll q,ll v);
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,c;
        cin>>n>>c;
        vector<ll> tree(N+1,0),lazy(N+1,0);
        while(c--){
            ll a,p,q,v;
            cin>>a;
            if(!a){
                cin>>p>>q>>v;
                update(tree,lazy,1,1,n,p,q,v);
                //cout<<"\n\n";
            }
            else{
                cin>>p>>q;
                cout<<get(tree,lazy,1,1,n,p,q)<<"\n";
            }
        }

        
    }

}
void update(vector<ll>& tree,vector<ll>& lazy,ll s,ll ss,ll se,ll p,ll q,ll v){
    //cout<<ss<<" "<<se<<" "<<s<<endl;
    if(lazy[s] != 0){
        tree[s] += (se-ss+1)*lazy[s];
        if(ss != se){
            lazy[2*s] += lazy[s];
            lazy[2*s+1] += lazy[s];
        }
        lazy[s]=0;
    }

    if(ss > se or q < ss or se < p) return ;
    if(p <= ss and q >= se){
        tree[s] += (se-ss+1)*v;
        if(ss != se){
            lazy[s*2] += v;
            lazy[s*2+1] += v;
        }
        return ;
    }

    ll mid = (ss + se)>>1;
    update(tree,lazy,s*2,ss,mid,p,q,v);
    update(tree,lazy,s*2+1,mid+1,se,p,q,v);

    tree[s] = tree[s*2] + tree[s*2+1];
}

ll get( vector<ll>& tree,vector<ll>& lazy,ll s,ll ss,ll se,ll p,ll q){
    if(lazy[s] != 0){
        tree[s] += 1ll* (se-ss+1)*lazy[s];
        if(se != ss){
            lazy[s*2] += lazy[s];
            lazy[s*2+1] += lazy[s];
        }
        lazy[s] = 0;
    }
    if(ss > se or se < p or ss > q) return 0;
    if(p <= ss and se <= q) return tree[s];

    ll mid = (se + ss)>>1;
    return get(tree,lazy,s*2,ss,mid,p,q) + get(tree,lazy,s*2+1,mid+1,se,p,q);
}

