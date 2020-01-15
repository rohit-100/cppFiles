#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,p,k;
        cin>>n>>p>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(),arr.end());
        vector<int>dp;
        dp.push_back(0);
        for(int i=0;i<n;i++){
            int ans = dp.back() + arr[i];
            if(i+1>=k){
                ans = min(ans,dp[i-k+1]+arr[i]);
            }
            dp.push_back(ans);
        }
        int ans = n;
        for(int i=n;i>=0;i--){
            if(dp[i] <= p){
                ans = i;
                break;
            }
        }
        cout<<ans<<endl;
    }
}

