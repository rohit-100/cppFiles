#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<vector<ll> > dp;
void calc(int i,int j,const vector<int>& arr,const vector<int>& rev){
    if(i >= j)return;
    const int n = arr.size();
    if(dp[i][j] != -1)return;
    calc(i+1,j-1,arr,rev);
    if(j-i > 0)
    dp[i][j] = 1ll*arr[i]*arr[j]+dp[i+1][j-1];
    else
        dp[i][j] = 1ll*arr[i]*arr[j];

}
int main(){

    int n;cin>>n;
    dp.assign(2*n,vector<ll>(2*n,-1));
    vector<int> arr;
    vector<int>rev(2*n);
    for(int i=0;i<2*n;i++){
        int x;cin>>x;arr.push_back(x);
        rev[2*n-1-i] = x;
    }
    

    
//     vector<vector<ll> > dp(2*n,vector<ll>(2*n,0));
    for(int len = 2;len <= 2*n;len+=2){
       for(int i=0;i+len < 2*n;i++){
           int j = i+len;
           calc(i,j,arr,rev);

       }
    }

    n = 2*n;
    ll ans = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
    
}
