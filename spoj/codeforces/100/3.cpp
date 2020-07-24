#include<bits/stdc++.h>
using namespace std;

struct node{
    int radius,fre;
    node(int radius,int fre):radius(radius),fre(fre){}
    bool operator < (const node &temp){
        return fre < temp.fre;
    }
};

int main(){

    int n;cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp[x]++;
    }
    vector<node> arr;
    for(auto val:mp){
        arr.push_back(node(val.first,val.second));
    }
    sort(arr.begin(),arr.end());
    vector<int>pq(3,0);
    vector<int> ans[3];
    for(node val:arr){
        int ind = 0;
        for(int j=1;j<3;j++)if(pq[j] < pq[ind])ind = j;
        pq[ind] += val.fre;
        for(int j=0;j<val.fre;j++)ans[ind].push_back(val.radius);

    }
    int minInd = 0;
    if(ans[1].size() < ans[minInd].size() )minInd = 1;
    if(ans[2].size() < ans[minInd].size() )minInd = 2;
    cout<<ans[minInd].size()<<endl;
    for(int i=0;i<ans[minInd].size();i++){
        vector<int>temp;
        temp.push_back(ans[0][i]);
        temp.push_back(ans[1][i]);
        temp.push_back(ans[2][i]);
        sort(temp.begin(),temp.end(),greater<int>());
        for(int val:temp)cout<<val<<" ";
        cout<<endl;
    }
        
//     reverse(arr.begin(),arr.end());
//     vector<pair<int,pair<int,int>>> ans;
//     long total = 0;
//     while(arr.size() > 2){
//         total += arr.back().fre;
//         int m = arr.size();
//         int ff = arr.back().fre;
//         arr[m-1].fre -= ff;
//         arr[m-2].fre -= ff;
//         arr[m-3].fre -= ff;
//         for(int j=0;j<ff;j++)ans.push_back({arr[m-3].radius,{arr[m-2].radius,arr[m-1].radius}});
//         while( arr.size() and arr.back().fre == 0)arr.pop_back();
//     }
//     cout<<total<<endl;
//     for(auto val:ans)cout<<val.first<<" "<<val.second.first<<" "<<val.second.second<<endl;

}
