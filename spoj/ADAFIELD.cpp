#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;
typedef pair<ll,ll> pii;
typedef pair<ll,pair<ll,ll> > piii;

ll get(multiset<ll> &,multiset<piii> &,ll ,multiset<piii> &);


int main(){

    int t;
    cin>>t;
    while(t--){
        multiset<piii>setx;
        multiset<piii>sety;
        multiset<ll>x;
        multiset<ll>y;
        ll n,m,q;
        cin>>n>>m>>q;
        x.insert(0);x.insert(m);
        y.insert(0);y.insert(n);
        setx.insert({m,{0,m}});
        sety.insert({n,{0,n}});
        while(q--){
            ll type,val;
            cin>>type>>val;
            if(type == 0)
                cout<<get(x,setx,val,sety);
            else 
                cout<<get(y,sety,val,setx);

            cout<<"\n";
            /*for(auto it:x){
                cout<<it<<" ";
           }
            cout<<"y set ";
            for(auto it:y){
                cout<<it<<" ";
           }
            cout<<endl;*/
            /*for(auto it:setx){
                cout<<"{"<<it.first<<"{"<<it.second.first<<" "<<it.second.second<<"}}    ";
            }
            cout<<"\n";*/


       }
}
}
ll get(multiset<ll> &x,multiset<piii> & setx,ll val,multiset<piii> &sety){
    auto it = x.upper_bound(val);
    
    ll b = *it;
    //cout<<*it<<endl;
    auto prev = --it;
    ll a = *prev;
    //cout<<a<<" "<<b<<endl;
    x.insert(val);
    setx.erase({b-a,{a,b}});
    setx.insert({val-a,{a,val}});
    setx.insert({b-val,{val,b}});
    return 1ll *(setx.rbegin()->first) *(sety.rbegin()->first);
}

