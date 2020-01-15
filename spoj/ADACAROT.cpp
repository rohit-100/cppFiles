#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;
const int N = 200007;
ll power(int a,int b){
    ll aa = a;
    aa%=mod;
    ll res = 1;
    while(b){
        if(b&1)res = (1ll*res*aa)%mod;
        b>>=1;
        aa = (1ll*aa*aa)%mod;
    }
    return res %mod;
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
      int n;
        ll fac[N];
        fac[0]=1;
        for(int i=1;i<N;i++){
            fac[i]=1ll*i*fac[i-1];
            if(fac[i] >= mod)fac[i] %= mod;
        //fac[i] = 1ll * fac[i-1] * i %mod;
        }

        
      while(cin >> n){
          ll res = 0;
          for(int x = 1;x<=n-1;x++){
            res = (res + (1ll * power(x,n-x-1)* power(n-x,x-1))%mod)%mod;
            //cout<<res<<endl;       

          }
          res = (1ll*res * fac[n])%mod;
          cout<<res<<endl;
      }

}
