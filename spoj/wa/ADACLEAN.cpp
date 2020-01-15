
/*
   i don't why the solution is wronng
   hash is first hash of k length substing
   

   hash = (hash - s[i-k])/53) + 53^k-1*s[i];

*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;

int power(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = (1ll*res*a)%mod;
        b>>=1;
        a = (1ll*a*a)%mod;
    }
    return res;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        set<ll>strs;
        ll hash=0;
        ll pk=1;
        for(int i=0;i<k;i++){
            hash = hash + (s[i]-'a'+1)*pk;
            if(hash >= mod)hash%=mod;
            pk = pk*33;
            if(pk >= mod) pk = pk%mod;
       }
        strs.insert(hash);
        pk =1ll* pk*power(33,mod-2);
        pk%=mod;
        for(int i=k;i<n;i++){
            hash = (0ll+(1ll*(hash-s[i-k]+'a'-1)*power(33,mod-2))%mod + (1ll*(s[i]-'a'+1)*pk)%mod)%mod;
            strs.insert(hash);
        }
        cout<<strs.size()<<endl;
     }
}
