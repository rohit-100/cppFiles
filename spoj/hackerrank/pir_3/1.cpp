#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
    }
    bool allneg = true;
    for(int val:arr){
        if(val >=0 ){
            allneg = false;
            break;
        }
    }
    if(allneg){
        cout<<*max_element(arr.begin(),arr.end());
        return 0; 
    }
    long long ans = 0;
    long long curr = 0;
    for(int val :arr){
        curr += val;
        if(curr > ans){
            ans  = curr;
        }
        if(curr < 0)
            curr = 0;
    }
    cout<<ans<<endl;
}
