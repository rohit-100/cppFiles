#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
#define ll long long 
ll power[N];
const int mod = (int)1e9+7;
const int prime = 103;
void init(){
    power[0] = 1;
    for(int i=1;i<N;i++)power[i] = power[i-1]*prime%mod;
}

int main(){
    init();
//     for(int i=0;i<100;i++)cout<<power[i]<<" ";
//     cout<<endl;
    int t;
    cin>>t;
    while(t--){
        string str;cin>>str;
        unordered_set<ll>st;
        int n = str.length();
        for(int i=0;i<n;i++){
            ll hash = 0;
            for(int j=i;j<n;j++){
                hash = (str[j]-'A'+1)*power[j-i+1]+hash;
                if(hash >= mod)hash%=mod;
                st.insert(hash);

            }
        }
        cout<<st.size()<<endl;
    }
    
}
