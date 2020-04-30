#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;cin>>n;
    vector<ll> arr(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    map<ll,ve
}
