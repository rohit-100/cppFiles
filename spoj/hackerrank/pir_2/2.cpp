#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;cin>>n;
    vector<int>arr;
    arr.push_back(0);
    for(int i=0;i<n;i++){
        int x;cin>>x;
//         if(!arr.size()){
//             arr.push_back(x);
//             continue;
//         }
        arr.push_back(arr.back()^x);
    }
    int x;cin>>x;
//     int ans = -1;
//     for(int i=0;i<=n;i++){
//         int req = x^arr[i];
// 
//     }
    map<int,vector<int> > mp;
    for(int i=0;i<=n;i++){
        mp[arr[i]].push_back(i);
    }
    int ans = -1;
    for(int i=0;i<=n;i++){
        int req = arr[i]^x;
        if(mp[req].size() > 0){
            ans = max(ans,mp[req].back()-i);
        }
    }
    cout<<ans<<endl;
}
