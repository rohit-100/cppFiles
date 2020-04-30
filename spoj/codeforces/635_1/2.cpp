#include<bits/stdc++.h>
using namespace std;
void take(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        int x;cin>>x;arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
}
int main(){

    int t;
    cin>>t;
    while(t--){
        int nr,ng,nb;cin>>nr>>ng>>nb;
        vector<int>a,b,c;
        take(a,nr);
        take(b,ng);
        take(c,nb);
    
        long long ans = (long long) 2e18;
        int i,j,k;
        i=0;j=0;k=0;
        while(i<nr and j<ng and k<nb){
            long long aa = a[i],bb = b[j],cc=c[k];
            ans = min(ans,(aa-bb)*(aa-bb) + (aa-cc)*(aa-cc)+(bb-cc)*(bb-cc));
            int mn = min(a[i],min(b[j],c[k]));
            if(mn == a[i]){
                i++;
            }
            else if(mn == b[j])j++;
            else k++;
        }
        cout<<ans<<endl;
    }
}
