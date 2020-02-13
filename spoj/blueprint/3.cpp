#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr;{for(int i=0;i<n;i++){int x;cin>>x;arr.push_back(x);}}
        sort(arr.begin(),arr.end());
        vector<int>fre(n+1,0);
        for(int val:arr)fre[val]++;
        int ind,maxi=0;
        for(int i=0;i<=n;i++){
            if(fre[i] > maxi){
                maxi = fre[i];
                ind = i;
            }
        }
        long  ans = (fre[ind]*(fre[ind]-1))/2;
        vector<int> fre1(n+1,0);
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        for(int val:arr)if(val != ind){
            ans += (fre[val]*(fre[val]-1))/2;
            fre1[abs(val - ind)]+= (fre[val])*fre[ind];
        }
        long temp = *max_element(fre1.begin(),fre1.end());
        cout<<max(ans,temp);
        cout<<" "<<ind<<endl;
    }
}
        
        
