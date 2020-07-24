#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,R,r;
    cin>>n>>R>>r;
    if(R >= 2*r){

        if(floor(3.14*(R-r)/r)>=n){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    else if(n== 1 and r <= R){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}
