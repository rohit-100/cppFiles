#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = 10005;
ll pr[N];
void seive(){
    for(ll i=0;i<N;i++)pr[i] = i;
    for(ll i=2;i<N;i++){
        if(pr[i] == i){
            for(ll j=2*i;j<N;j+=i)pr[j] = i;
        }
    }
}
ll power(int a,int b,int mod=1e9+7){
     ll res = 1;
      while(b){
           if(b&1)res = 1ll*res*a;
            a=1ll*a*a;
            b>>=1;
      }
       return res;
} 


int  main(){
    seive();
//     for(ll i=0;i<50;i++)cout<<pr[i]<<" ";
//     cout<<endl;
    ll t;
    cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vector<ll>arr;{for(int i=0;i<n;i++){int x;cin>>x;arr.push_back(x);}}
        ll freq[N];
        for(ll i=0;i<N;i++)freq[i] = 0;
        for(ll i=0;i<n;i++){
            ll val = arr[i];
            ll ff = 1;
            while(val > 1){
                ll prime = pr[val];
                val = val/prime;

                if(prime == pr[val]){
                    ff += 1;
                }
                else{
                    if(freq[prime] >= ff);
                    else{
                        freq[prime] = ff;
                    }
                    ff = 1;
                }
                if(val == 1 and ff > 1){
                    if(freq[prime] >= ff);
                    else{
                        freq[prime] = ff;
                    }
                    ff = 1;
                    
                }
            }
            
        }
//         for(ll i=0;i<50;i++)cout<<freq[i]<<" ";
//         cout<<endl;
        map<ll,int> mp;
        for(ll i=0;i<N;i++){
            if(freq[i])mp[i] = freq[i];
        }
        ll ans = m;
        ll to_incre = 0;
        for(ll i=m;i>=1;i--){
            ll ff = 1;
            ll val = i;

            ll increment = 0;
            while(val>1){
                ll prime = pr[val];
                val = val/prime;

                if( prime == pr[val] ){
                    ++ff;
                }
                else{
                    if(freq[prime] < ff){
                        increment += (ff - freq[prime])*prime;
                        ff = 1;
                    }
                }
                
                if(val == 1 and ff > 1){
                    if(freq[prime] < ff){
                        increment += power(prime,ff-freq[prime]);
                    }
                    
                }
            }
            if(to_incre <= increment){
                ans = i;
                to_incre = increment;
            }
        }
        cout<<ans<<endl;
    }
}
