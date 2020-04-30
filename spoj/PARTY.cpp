#include<bits/stdc++.h>
using namespace std;

int main(){

    while(true){
        int m,n;cin>>m>>n;
        if(m==0 and n==0)break;

        int dp[2][500];
        memset(dp,0,sizeof(dp));
        int ind = 0;
        int total = 0;
        for(int i=0;i<n;i++){
            int price,fun;cin>>price>>fun;
            total = price;
            for(int j=0;j<=m;j++)dp[1-ind][j] = dp[ind][j];
            ind = 1-ind; 
            for(int j=0;j<=m;j++){
                if(dp[1-ind][j] != 0 and j+price <= m){
                    dp[ind][j+price] = max(dp[1-ind][j+price],dp[1-ind][j]+fun);
                }
            }
            dp[ind][price] = max(dp[ind][price],fun);

        }
//         for(int i=0;i<=m;i++)cout<<dp[ind][i]<<" ";
//         cout<<endl;
        int ans =dp[ind][0];
        int inx = 0;
        for(int i=0;i<=m;i++){
            if(dp[ind][i] > ans){
                ans = dp[ind][i];
                inx = i;
            }
        }
        if(ans != 0)
        cout<<inx<<" "<<ans<<endl;
        else cout<<total<<" "<<ans<<endl;
    }
}
