#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void fun(vector<int>& arr,vector<vector<ll> >& dp,int i,int j){
    //cout<<i<<" "<<j<<endl;
    if(i==j)dp[i][i] = 0; 
    if(dp[i][j] != -1)return;
    ll ans = 1e15;
    for(int k = i;k<j;k++){
        ll leftsum = arr[k]-arr[i-1];
        ll rightsum = arr[j]-arr[k];
        leftsum%=100;
        rightsum%=100;
        //cout<<leftsum<<" "<<rightsum<<endl;
        fun(arr,dp,i,k);
        fun(arr,dp,k+1,j);
        ans = min(ans,dp[i][k]+dp[k+1][j]+leftsum*rightsum);
    }
    dp[i][j]=ans;
    
}

int main(){
    int n;while(cin>>n){
        vector<int>arr;
        arr.push_back(0);
        for(int i=1;i<=n;i++){int x;cin>>x;arr.push_back(x+arr[i-1]);};
        
        vector<vector<ll> > dp(n+1,vector<ll>(n+1,-1));
        fun(arr,dp,1,n);
        //for(int val:arr)cout<<val<<" ";
        //cout<<endl;
        cout<<dp[1][n]<<endl;
    }
}
