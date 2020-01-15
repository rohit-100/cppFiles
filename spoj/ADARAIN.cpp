#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,w;
    cin>>n>>m>>w;
    vector<int>arr(w+1,0);
    while(n--){
        int l,r;
        cin>>l>>r;
        arr[l]++;
        arr[r+1]--;
    }
    for(int i=1;i<=w;i++)arr[i]+=arr[i-1];
    while(m--){
        int a;
        cin>>a;
        cout<<arr[a]<<endl;
    }
}
