#include<bits/stdc++.h>
using namespace std;
int dp[3][2000][2000];

int fun(int i,int j,int k){
    //cout<<"j "<<j<<" k  "<<k<<endl;
    if(j<=0 or k<=0)return -1;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    if(i==0){
        return dp[i][j][k] =1+ max(fun(1,j-5,k-10),fun(2,j-20,k+5));
    }
    else  if(i==1){
        return dp[i][j][k] =1+ max(fun(0,j+3,k+2),fun(2,j-20,k+5));
    }
    else{
        return dp[i][j][k] =1+ max(fun(0,j+3,k+2),fun(1,j-5,k-10));
    }
}



int main(){

    int t;
    cin>>t;
    while(t--){
        int h,a;
        cin>>h>>a;
        memset(dp,-1,sizeof(dp));
        fun(0,h,a);
        fun(1,h,a);
        fun(2,h,a);
        cout<<max(dp[0][h][a],max(dp[1][h][a],dp[2][h][a]))<<endl;

    }
}
