#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,p;cin>>n>>p;
        vector<vector<int> > arr(n,vector<int>(n,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<"1 "<<i<<" "<<i<<" "<<j<<" "<<j<<endl;
                cout.flush();
                cin>>arr[i-1][j-1];
            }
        }
        cout<<"2\n";
        int ans ;
        for(auto row : arr){
            for(int val:row)cout<<val<<" ";
            cout<<endl;

        }
        cout.flush();
        cin>>ans;
        if(ans == 1)continue;
        else exit(0);
    }
}