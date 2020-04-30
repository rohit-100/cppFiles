#include<bits/stdc++.h>
using namespace std;
int power(int a,int b,int mod=1e9+7){
     int res = 1;
      while(b){
           if(b&1)res = 1ll*res*a%mod;
            a=1ll*a*a%mod;
            b>>=1;
      }
       return res;
} 
int main(){

    int n;cin>>n;
    int dp[3][n+1];
    dp[0][0] = 0;
    dp[1][0] = 1;
    dp[2][0] = 2;
    for(int j=1;j<n;j++){
        for(int i=0;i<3;i++){
            if(j==0){
                dp[i][j] = dp[i-1][j]+1;
                if(dp[i][j] >= mod)dp[i][j] %= mod;
            }

            else{
                dp[i][j] = (dp[i][j-1]+1)+(dp[i-1][j]+1);
                if(dp[i][j] >= mod)dp[i][j] %= mod;
            }
        }
    }
    cout<<3*power(2,dp[2][n-1])%mod;


}
