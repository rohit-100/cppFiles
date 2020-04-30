#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<long>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
        }
        if(n==1){
            cout<<a[0];
            cout<<endl;
            continue;
        }
        vector<long>diff(n);
        diff[0] = a[0]-b[n-1];
        for(int i=1;i<n;i++)diff[i] = a[i]-b[i-1];
        unsigned long long total = 0;
        for(int val:diff){
            if(val > 0 )total += val;
        }
        cout<<total + *min_element(a.begin(),a.end())<<endl;
    }
}
