#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        int rest = a-b;
        if(rest <= 0){
            cout<<b<<endl;
            continue;
        }
        if(rest > 0 and c-d <= 0){
            cout<<"-1"<<endl;
            continue;
        }
        int diff = c-d;
        int times = ceil(rest*1.0/diff);
//         cout<<"times = "<<times<<endl;
        cout<<0ll + b + 1ll*times*c<<endl;
    }
}
