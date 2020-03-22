#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        if(abs(a-b) % abs(c-d) == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
