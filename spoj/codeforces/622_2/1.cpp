#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
int fun(int i,int a,int b,int c){
    if(a==0 and b==0 and c==0)return 0;
    if(a<0 or b<0 or c<0)return INT_MIN;
    if(i < 0)return 0;
    int ans = fun(i-1,a,b,c);
    if(arr[i]&(1<<0))--a;
    if(arr[i]&(1<<1))--b;
    if(arr[i]&(1<<2))--c;
    ans = max(ans, 1+ fun(i-1,a,b,c));
    return ans;

}
int main(){

    int t;
    cin>>t;
    for(int i=1;i<8;i++){
        arr.push_back(i); 
    }
    while(t--){
        int a,b,c;cin>>a>>b>>c;
        cout<<fun(6,a,b,c)<<endl;

    }
}
