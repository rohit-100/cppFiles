#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i]; 
        }
        int ans = 0;
        int diff = 0;
        int prev = arr[0];
        for(int i=1;i<n;i++){
            diff = max(diff,prev-arr[i]);
            prev = max(prev,arr[i]);
        }
        if(diff == 0)cout<<0<<endl;
        else
        cout<<ceil(log2(diff+1))<<endl;
    }
}
