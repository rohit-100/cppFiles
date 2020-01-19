#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> >dp;
int get(int a,int b,int n){
    if(n<0)return 0;
    if(dp.find({a,b}) != dp.end()or dp.find({b,a}) != dp.end())return 0;
    dp.insert({a,b});
    return 1+get(a+1,b,n-b)+get(a,b+1,n-a);
}

int main(){

    int n;cin>>n;
    cout<<get(1,1,n-1);
}
