#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > dp;
int fun(int l,int r,string& str){
    if(dp[l][r] != -1)return dp[l][r];
    if(l>=r)return 0;
    return dp[l][r] = (str[l] == str[r]?fun(l+1,r-1,str):1+min(fun(l+1,r,str),fun(l,r-1,str)));
}


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        dp.clear();
        int n = s.length();
        dp.assign(n,vector<int>(n,-1));
        cout<<fun(0,s.length()-1,s);
        cout<<endl;
    }
}
