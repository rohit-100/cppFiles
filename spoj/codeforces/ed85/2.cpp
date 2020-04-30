#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.rbegin(),arr.rend());
        double ans = 0.0;
        bool flag = true;
        for(int i=0;i<n;i++){
            ans += arr[i];
            if(ans/(i+1)<x){
                cout<<i<<endl;
                flag = false;
                break;
            }
            
        }
        if(flag)
        cout<<n<<endl;

    }
}
