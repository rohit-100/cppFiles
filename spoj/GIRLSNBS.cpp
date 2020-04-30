#include<bits/stdc++.h>
using namespace std;

int main(){
    while(true){

        int n,m;cin>>n>>m;
        if(n == -1 and m == -1)break;
        if(n == 0 and m==0){
            cout<<0<<endl;
            continue;
        }
        
        int mx = max(n,m);
        int mn = min(n,m);
        int places = mn+1;
        int ans = (mx+places-1)/places;
        if(ans == 0)ans = 1;
        cout<<ans<<endl;
    }
}
