#include<bits/stdc++.h>
using namespace std;
vector<vector<long long int > > dp;
long long fun(vector<int>& arr,int low ,int high){
    
    if(low > high)return 0;
    if(dp[low][high] != -1)return dp[low][high];
    int age = arr.size()-high+low;
     dp[low][high] = max(1ll*arr[low]*age + fun(arr,low+1,high),
            1ll*arr[high]*age + fun(arr,low,high-1));

//    cout<<low<<" "<<high<<" ";
  //   cout<<dp[low][high]<<" "<<arr[low]*age<<endl;
     return dp[low][high];
}


int main(){
    int n;cin>>n;
    vector<int>arr; 
    dp.assign(n+1,vector<long long int>(n+1,-1));
    for(int i=0;i<n;i++){int x;cin>>x;arr.push_back(x);}
//    for(int val:arr)cout<<val<<" ";
//    cout<<endl;
    fun(arr,0,n-1);
    cout<<dp[0][n-1]<<endl;
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
}
