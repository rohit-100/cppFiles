#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int O,N;cin>>O>>N;
        int n;cin>>n;
        int dp[22][80];
        for(int i=0;i<22;i++){
            for(int j=0;j<80;j++){
                dp[i][j] = 1000000000;
                 
            }
        }
        for(int i=0;i<n;i++){
            int oo,nn,wt;cin>>oo>>nn>>wt;
            int dp1[22][80];
            for(int j=0;j<22;j++){
                for(int k = 0;k<80;k++){
                    dp1[j][k] = dp[j][k];
//                     cout<<dp1[j][k]<<" ";
                }
//                 cout<<endl;
            }
//             cout<<endl<<endl;
            for(int j=0;j<22;j++){
                for(int k = 0;k<80;k++){
                    
                        if(j+oo < 22 and k+nn <80){
                            dp[j+oo][k+nn] = min(dp1[j+oo][k+nn],dp1[j][k]+wt);
//                             if(dp[j+oo][k+nn] != 1000000000)cout<<j<<" "<<k<<endl;
                    }
                }
            }
            dp[oo][nn] = min(wt,dp[oo][nn]);
//             cout<<dp[oo][nn]<<endl;
        }
        int ans = 1000000000;
        for(int i=O;i<22;i++){
            for(int j=N;j<80;j++)
            ans = min(ans,dp[i][j]);
        }
        cout<<ans<<endl;

    
    }
}
