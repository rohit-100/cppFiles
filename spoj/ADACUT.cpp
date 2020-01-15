#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;

int main(){

    int n;
    cin>>n;
    ll arr[n+1];
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr ,arr+n);
    ll sum2=0;
    ll ans = LLONG_MAX;
    for(int i=0;i<n;i++){
        sum -= arr[i];
        ans = min(ans,sum2+sum-1ll*(n-i-1)*arr[i]);
        sum2 += arr[i];
       // cout<<ans<<endl;
    }
    cout<<ans;


}
