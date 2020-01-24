#include<bits/stdc++.h>
using namespace std;
int fun(vector<vector<vector<int> > >& dp,vector<int>&arr,int i,int j,int turn){
    if(i>j)return 0;
    if(dp[i][j][turn] != -1)return dp[i][j][turn];
    if(turn == 1){
        if(arr[i] >= arr[j])return dp[i][j][turn]=arr[i] + fun(dp,arr,i+1,j,1-turn);
        else return dp[i][j][turn] = arr[j]+ fun(dp,arr,i,j-1,1-turn);
    }
    else{
        return dp[i][j][turn] = max(arr[i]+fun(dp,arr,i+1,j,1-turn),arr[j]+fun(dp,arr,i,j-1,1-turn));
    }

}
int main(){

    int n;
    while(true){
        cin>>n;
        if(n==0)return 0;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<vector<vector<int> > > dp(n,vector<vector<int> >(n,vector<int>(2,-1)));
        /*for(int len=1;len<=n;len++){
            for(int i = 0;i<n;i++){
                int j = min(n-1,i+len-1);
                if(i==j)dp[i][i] = arr[i];
                else {
                    dp[i][j] = arr[i]+dp[i+1][j];
                    dp[i][j] = max(dp[i][j],dp[i][j-1]+arr[j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
                 
            }
            cout<<endl;
        }
        deque<int>dq;
        for(int val:arr)dq.push_back(val);
        int ans =0;
        while(!dq.empty()){
            ans
        }*/
        fun(dp,arr,0,n-1,0);
        cout<<dp[0][n-1][0]<<" "<<dp[1][n-1][1]<<endl;
    }
}
