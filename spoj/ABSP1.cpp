#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;

int main(){
    int t,n;
    cin>>t;
    while(t-->0){
        cin>>n;
        vector<ll>arr(n+1,0);
        for(int i=1;i<=n;i++)cin>>arr[i];
        ll total = accumulate(arr.begin(),arr.end(),0);
        ll ans = 0;
        ll m=n;
        for(int i=1;i<n;i++){
            m--;
            total -= arr[i];
            ans += abs(total - m*arr[i]);
        }
        cout<<ans<<endl;
    }

}
