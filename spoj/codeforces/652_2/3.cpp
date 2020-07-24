#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> val(n),wt(k);
        for(int i=0;i<n;i++)cin>>val[i];
        for(int i=0;i<k;i++)cin>>wt[i];
        sort(wt.begin(),wt.end() , greater<int>());
        sort(val.begin(),val.end());
        long long ans = 0;
        int j = n-1;
        for(int i=k-1;i>=0;i--){
            if(wt[i] == 1)ans += 2ll*val[j];
            else{
                ans += val[j];
            }
            j--;
            wt[i]--;
        }
//         cout<<"ans = "<<ans<<endl;
        int base = 0;
        for(int temp:wt){
            if(temp == 0)continue;
            int mn = val[base];
            for(int j=base;j<base+temp;j++)mn = min(mn,val[j]);
            ans += mn;
            base += temp;
        }
        cout<<ans<<endl;



    }
}
//         int len = 0;
//         long long ans = 0;
//         for(int ff:wt){
//             set<int> st;
//             for(int i=len;i<len+ff;i++){
//                 st.insert(val[i]);
//             }
//             ans += *st.begin();
//             ans += *--st.end();
//             len += ff;
// //             cout<<*st.begin()<<" "<<*--st.
// 
//         }
//         cout<<ans<<endl;
//         int temp = k;
//         long long ans = 0;
//         ans += accumulate(val.begin()+n-k,val.end(),0ll);
//         int len = 0;
//         for(int temp : wt){
//             --temp;
//             int mn = val[len];
//             for(int i=len;i<len+temp;i++)mn = min(mn,val[i]);
//             ans += mn;
//             len += temp;
//             if(len + k == n)break;
//             cout<<"ans = "<<ans<<endl;
// 
//         }
//         cout<<ans<<endl;
