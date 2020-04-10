#include<bits/stdc++.h>
using namespace std;
template<typename T>
ostream& operator<< (ostream& out,const vector<T>& arr){
    for(T val:arr)
        out<<val<<" ";
    return out;
}
int main(){

    int n,m;cin>>n>>m;
    vector<int>arr(m+1);
    for(int i=1;i<=m;i++){
        cin>>arr[i]; 
    }
    long total = accumulate(arr.begin(),arr.end(),0);
    if(total < n){
        puts("-1");
        return 0 ;
    }
    for(int i=1;i<=m;i++){
        if(n < i+arr[i]-1){
            puts("-1");
            return 0 ;
        }
    }
    vector<int>done(m+1);
    for(int i=1;i<=m;i++){
        total -= arr[i];
        done[i] = min((long)arr[i],total >= n-i?1:(n-i-total+1));

    }
    int ind = 1;
    for(int i=1;i<=m;i++){
        int val = done[i];
        done[i] = ind;
        ind += val;
    }
    for(int i=1;i<=m;i++)cout<<done[i]<<" ";
    cout<<endl;
}
