#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N = 1000005;
ll pr[N];
void seive(){
    for(ll i=1;i<N;i++)pr[i] = i;
    for(ll i=2;i<N;i++){
        if(pr[i] == i){
            for(ll j=2*i;j<N;j+=i)pr[j]=i;
        }
    }

}
ll get_fac(ll  num){
    for(ll i=2;i<N;i++){
        if(pr[i] == i and num%i==0)return i;

    }
    return -1;
}
vector<ll > get(ll num){
    set<ll >primes ;
    bool flag = false;
    while(num>1){
        if(num >= N){
            ll fac = get_fac(num);
            if(fac == -1){
                flag = true;
                primes.insert(num);
                break;
            }
            else{
                primes.insert(fac);
                num /= fac;
            }
        }
        else{
            primes.insert(pr[num]);
            num/=pr[num];
        }
    }
    return vector<ll >(primes.begin(),primes.end());
}
ll power(ll a,ll b,ll mod=1e9+7){
     ll res = 1;
      while(b){
           if(b&1)res = 1ll*res*a%mod;
            a=1ll*a*a%mod;
            b>>=1;
      }
       return res;
}
const ll mod = 1000000007;
ll summ(ll val,ll n){
    ll res = 0;
    ll times = n/val;
    res = (((times)%mod)* (times+1)%mod)%mod;
    res *= power(2,mod-2);
    res %= mod;
    res = val*res%mod;
    
    return res;
}
int main(){
    seive();
//     for(ll val:ff)cout<<val<<endl;

    ll n;cin>>n;
    vector<ll> ff = get(n);
    ll total = summ(1,n);
    ll m = ff.size();
    ll  i=1; 
//     cout<<m<<endl;
    while(i<(1<<m)){
        ll count = __builtin_popcount(i);

        ll  j = i;
        ll ind = 0;
        ll val = 1;
        while(j){
            if(j & 1){
                val *= ff[ind];
            }
            ind++;
            j>>=1;
        }
        if(count % 2== 0){
            total += summ(val,n);
            while(total >= mod)total -= mod;
        }
        else{
            total -= summ(val,n);
            while(total<0) total += mod;
        }
        ++i;
    }
    cout<<total<<endl;
}
