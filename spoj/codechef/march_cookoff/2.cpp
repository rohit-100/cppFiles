#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr;{for(int i=0;i<n;i++){int x;cin>>x;arr.push_back(x);}}
        int maxi = *max_element(arr.begin(),arr.end());
        multiset<int>st;
        for(int i=0;i<n/2;i++)st.insert(arr[i]);
        int left = n/2-1,right = n-1;
        int ans = 0;
        int count = 0;
        for(;count < n;){
            auto temp = st.end();
            --temp;
//             cout<<*temp<<endl;
            if(maxi == *temp) ++ans;
            st.insert(arr[right]);
            st.erase(st.find(arr[left]));
            --left;
            --right;
            if(left < 0)left += n;
            ++count;
        }
        cout<<n-ans<<endl;
//         stack<pii> a,b;
//         for(int i=0;i<n/2;i++){
//             if (a.empty()){
//                 a.push({arr[i],arr[i]});
//             }
//             else
//                 a.push({arr[i],max(arr[i],a.top().second)});
//         }
//         bool toggle = true;
//         int ans = 0;
//         for(int i=0;i<n;i++){
//             if(toggle){
//                 int temp = -1;
//                 if(!b.empty())temp = max(temp,b.top().second);
//                 if(!a.empty()) temp = max(temp,a.top().second);
//                 if(temp == maxi) ++ans;
//                 a.pop();
//                 if(b.empty()){
//                     b.push({arr[n-1-i],arr[n-1-i]});
//                 }
//                 else{
//                     b.push({arr[n-1-i],max(arr[n-1-i],b.top().second)});
//                 }
//                 if(a.empty())toggle = false;
//             }
//             else{
//                 int temp = -1;
//                 if(!b.empty())temp = max(temp,b.top().second);
//                 if(!a.empty()) temp = max(temp,a.top().second);
//                 if(temp == maxi) ++ans;
//                 b.pop();
//                 if(a.empty()){
//                     a.push({arr[n-1-i],arr[n-1-i]});
//                 }
//                 else{
//                     a.push({arr[n-1-i],max(arr[n-1-i],a.top().second)});
//                 }
// 
//             }
// 
//         }
//         cout<<n-ans<<endl;
            

    }
}
