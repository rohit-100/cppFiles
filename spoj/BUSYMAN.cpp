#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;

}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<pair<int,int> >arr;
        for(int i=0;i<n;i++){int x,y;cin>>x>>y;arr.push_back({x,y});}
        sort(arr.begin(),arr.end(),comp);
        //for(auto val:arr)cout<<val.first<<" "<<val.second<<endl;
        int ans = 1;
        vector<int>dp(n,1);
        for(auto val:arr){
            int start = val.first;
            int end = val.second;
            int low = 0,high=n-1,ans=-1;
            while(low <= high){
                int mid = (low+high)>>1;
                if(arr[mid].second >)
            }
        }
    }
}
