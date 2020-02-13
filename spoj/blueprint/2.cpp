#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
vector<long long>fac;
void init(){
    const int N = 100005;
    fac.resize(N,0);
    fac[0] = 1;
    for(int i=1;i<N;i++){
        fac[i] = 1ll*i*fac[i-1]%mod;
    }
}

int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n; 
        long long  ans = 0;
        for(int i=1;i<=n;i++){
            int left = i-1;
            int right = n-i;
            ans += 1ll*fac[left]*fac[right]%mod;
        }
        cout<<ans<<endl;
    }
}
