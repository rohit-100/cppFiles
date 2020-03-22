#include<bits/stdc++.h>
using namespace std;

vector<bool>ans;
vector<int>arr;
void fun(int ind,int val){
    cout<<arr[ind]<<val<<endl;
    for(int val:ans)cout<<val<<" ";
    cout<<endl;
    int newval = val%arr[ind];
    if(ans[newval])return ;
    ans[newval] = true;
    int newind = upper_bound(arr.begin(),arr.end(),newval)-arr.begin();
    for(int i=0;i<newind;i++)fun(i,newval);
}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        
        arr.assign(n,0);for(int i=0;i<n;i++){
            cin>>arr[i]; 
        }

        sort(arr.begin(),arr.end());
        ans.assign(arr.back(),false);
        for(int i=0;i<n;i++){
            fun(i,x);
        }
        int count = 0;
        for(int val:ans){

        if(val)count++;
        cout<<val<<endl;
    }
        cout<<count<<endl;
    }
}
