#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        n*=2;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<int> fre[2];
        for(int i=1;i<=n;i++){
            fre[arr[i-1]%2].push_back(i);
        }
//         cout<<fre[0].size()<<" "<<fre[1].size()<<endl;
        if(fre[0].size()%2){
            fre[0].pop_back();
            fre[1].pop_back();

        }
        else{
            if(fre[0].size() != 0){
                fre[0].pop_back();
                fre[0].pop_back();
            }
            else{

                fre[1].pop_back();
                fre[1].pop_back();
            }
        }
        for(int i=0;i<fre[0].size();i+=2){
            cout<<fre[0][i]<<" "<<fre[0][i+1]<<"\n";
        }

        for(int i=0;i<fre[1].size();i+=2){
            cout<<fre[1][i]<<" "<<fre[1][i+1]<<"\n";
        }
    }
}
