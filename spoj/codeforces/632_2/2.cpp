#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i]; 
        }
        for(int i=0;i<n;i++){
            cin>>b[i]; 
        }
        bool dp[3][n+1];
        for(int i=0;i<3;i++)for(int j=0;j<=n;j++)dp[i][j] = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++)dp[j][i+1] = dp[j][i];
            if(a[i] == -1){
                dp[0][i+1] |= true;
            }
            else if( a[i] == 0 )dp[1][i+1] |= true;
            else dp[2][i+1] |= true;
        }
        bool flag = true;
        for(int i=n-1;i>=0;i--){
            int diff = b[i] - a[i];
            if(diff > 0 and dp[2][i]==false or diff<0 and dp[0][i] == false){
                flag = false;
                break;
            }
        }
        if ( !flag )cout<<"NO\n";
        else cout<<"YES\n";

    }
}
