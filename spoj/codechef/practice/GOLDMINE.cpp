#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n; 
        int dp[n+1];
        dp[0]=1;
        dp[1]= 0;
        for(int i=2;i<=n;i++){
            dp[i] = 0;
            dp[i]+=dp[i-2];
            if(dp[i]>=mod)dp[i]%=mod;
            if(i > 2)
                dp[i]+=dp[i-3];
            if(dp[i]>=mod)dp[i]%=mod;

        }
        cout<<dp[n]<<endl;
    }
}
