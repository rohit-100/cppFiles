#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int ans = 0;
        long start = 5;
        while(n/start !=0){
            ans += n/start;
            start*=5;
        }
        cout<<ans<<endl;

    }
}
