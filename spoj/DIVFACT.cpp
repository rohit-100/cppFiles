#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int pr[N];
unordered_map<int,int> mp[N];
void init(){
    for(int i=0;i<N;i++)pr[i]= i;
    for(int i=2;i<N;i++){
        if(i == pr[i]){
            for(long j = 1ll*i*i;j<N;j+=i)pr[j] = i;
        }
    }
    for(int i=2;i<N;i++){
//         mp[i] = mp[i-1];
        for(auto it = mp[i-1].begin();it != mp[i-1].end();++it){
            mp[i][it->first] = it->second;
        }
        int val = i;
        while(val != 1){
            mp[i][pr[val]]++;
            val /= pr[val];
        }
    }

}
const int mod = (int)1e9+7;
int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        long long ans = 1;
        for(auto it=mp[n].begin();it != mp[n].end();++it){
            ans*=(it->second +1);
            if(ans >= mod)ans%=mod;
        }
        cout<<ans<<endl;
    }
     
}
