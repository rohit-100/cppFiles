#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > arr (n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cin>>arr[i][j];
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cout<<arr[i][j]<<" ";
            cout<<endl;
        }*/
        //memset(dp,0,sizeof(dp));
        int last = 1<<n;
        vector<ll> dp(last,0);
        dp[0]=1;
        for(int i=0;i<last-1;i++){
            int pp = __builtin_popcount(i);
            for(int k=0;k<n;k++)if(arr[pp][k] and i^(1<<k)){
                int j = i|(1<<k);
                if(j==3)cout<<i<<" "<<k<<endl;
                dp[j]+=dp[i];
                //cout<<j<<endl;
            }
        }
        for(int i=0;i<min(last,8);i++)cout<<dp[i]<<" ";
        cout<<endl;
        cout<<dp[last-1]<<endl;
    }
}

