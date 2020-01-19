#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<long>arr(n+1,0);
        while(m--){
            int l,r,val;
            cin>>l>>r>>val;
            arr[l]+=val;
            arr[r+1]-=val;

        }
        for(int i=1;i<=n;i++)arr[i]+=arr[i-1];
        int q;
        cin>>q;
        //for(int val:arr)cout<<val<<" ";
        cout<<endl;
        while(q--){
            int ind;
            cin>>ind;
            cout<<arr[ind]<<endl;
        }
    }
}
