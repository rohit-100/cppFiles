#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n== 1 or n== 2){
            cout<<0<<endl;
            continue;
        }
        long long int z=1,o=0,t=0;
        long long dp[3][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        dp[1][0] = 0;
        dp[2][0] = 0;
        const int mod = 1000000007;
        for(int i=1;i<=n;i++){
            long long temp = dp[1][i-1];
            temp *=2;
            temp += dp[0][i-1];
           dp[2][i] = dp[1][i-1];
           dp[1][i] = dp[0][i-1];
           dp[0][i] = temp;
           if(dp[0][i]>=mod)dp[0][i] %= mod;
        }
        long long fff = dp[2][n-1]-dp[2][n-3];
        if(fff < 0)fff += mod;
        cout<<4ll*fff<<endl;

    }
}
