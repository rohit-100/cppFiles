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
        
        int ans = 0;
        int last = -1;
        for(auto val:arr){
            if(val.first>=last){
                ans ++;
                last = val.second;
            }
        }
        cout<<ans<<endl;
    }
}
