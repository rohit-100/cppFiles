#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e8;

int bs(vector<int>&right,int val,int high){
    int low = 0;
    int ans =high;
    while(low <= high){
        int mid = (low + high)/2;
        if(right[mid] <= val){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;




}


int main(){
    int n;
    cin>>n;
    while(n != -1){
        vector<pair<int,int> > arr;
        vector<int>right;
        arr.push_back({0,0});
        right.push_back(0);
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            arr.push_back({x,y});
            right.push_back(y);
        }
        sort(right.begin(),right.end()); 
        sort(arr.begin(),arr.end(),[](pair<int,int> a,pair<int,int> b){return a.second < b.second;});
        ll dp[n+2];
        dp[0]=0;
        for(int i=2;i<=n;i++)dp[i]=1;
        dp[1]=1;
        for(int i=1;i<=n;i++){
            dp[i] += dp[i-1];
            int ind =upper_bound(right.begin(),right.end(),arr[i].first)-right.begin();// bs(right,arr[i].first,i-1);
            dp[i] += dp[--ind];
            if(dp[i] >= mod ) dp[i]%=mod;
            //cout<<ind<<endl;
            //cout<<dp[i]<<" ";
        }
        
    string ans = to_string(dp[n]);
    int sz = ans.size();
    while(sz++ <  8)ans  = "0"+ ans;
    cout<<ans<<endl;
    cin>>n;
    }

}
