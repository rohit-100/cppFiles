#include<bitsstdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        long long  n,m;
        cin>>n>>m;
        bool ans = true;
        long long ll = m,hh = m;
        long long  prev = 0;
        for(int i=0;i<n;i++){
            long long  t,l,h;cin>>t>>l>>h;
            long long  diff = t-prev;
            if(ll-diff > h or hh+diff < l){
                ans = false;
                
            }
            else{
                long long left = ll-diff;
                long long right = hh+diff;
                ll = max(l,left);
                hh = min(h,right);
//                 if(ll-diff <= l and h<=hh + diff){
//                     ll = l;
//                     hh = h;
//                 }
//                 else if(ll-diff <= l){
//                     ll = l;
//                     hh = h+diff;
//                 }
//                 else{
//                     ll = ll-diff;
//                     hh = h;
//                 }
                prev = t;

//                 ll = l;
//                 hh = h;
//                 prev = t;
            }
        }
        if(ans){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
