#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int>arr(k);
        for(int i=0;i<k;i++)cin>>arr[i];
        sort(arr.begin(),arr.end());
        n = 2*n;
        ll dp[200][200];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        int kk = 0;
        for(int i=1;i<=n;i++){
            bool matched = false;
            for(int j=0;j<=n;j++){
                if(i==arr[kk]){
                    matched = true;
                    dp[i][j] = dp[i-1][j-1];
//                     cout<<i<<"*** "<<j<<endl;
                }
                else{
                    if(j-1>=0)
                        dp[i][j] = dp[i-1][j-1];
                    if(j+1 <= n)
                        dp[i][j] += dp[i-1][j+1];
                }
            }
            if(matched == true)++kk;
        }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 cout<<dp[i][j]<<" "; 
//             }
//             cout<<endl;
//         }
        cout<<dp[n][0]<<endl;

    }
}
