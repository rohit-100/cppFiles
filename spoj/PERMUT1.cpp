#include<bits/stdc++.h>
using namespace std;
long dp[50][50];
int fun(int n,int k){
    if(n==0)return 0;
    if(k ==0 )return 1;
    if(dp[n][k] != -1)return dp[n][k];
    long  ans = 0;
    for(int i=0;i<n && k-i>=0;i++)
        ans += fun(n-1,k-i);
    return dp[n][k] = ans;
}


int main(){
    int _;cin>>_;
    while(_--){
        int n,k;
        for(int i=0;i<50;i++)for(int j=0;j<50;j++)dp[i][j] = -1;
        cin>>n>>k;
        cout<<fun(n,k)<<endl;
    }
}
