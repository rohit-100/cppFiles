#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
vector<ppi> arr;
int main(){
    int t;
    cin>>t;
    while(t--){
        arr.clear();
        int n;cin>>n;
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            arr.push_back({{x,x+y-1},z});
        }
        sort(arr.begin(),arr.end(),[](ppi const& a,ppi const& b)->bool{
                return a.first.second < b.first.second;
                });
        int dp[n+1];
        dp[0] = 0;
        vector<int>ends;
        ends.push_back(-1);
        for(auto val:arr)ends.push_back(val.first.second);
        for(int i=1;i<=n;i++){
            int start = arr[i-1].first.first;
            auto it =lower_bound(ends.begin(),ends.end(),start) - ends.begin();
            --it;
            dp[i] = arr[i-1].second + dp[it];
            dp[i] = max(dp[i],dp[i-1]);
        }
        cout<<dp[n]<<endl; 
    }
     
}
