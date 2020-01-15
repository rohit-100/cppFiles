#include<bits/stdc++.h>
using namespace std;
const int N = 20007;
const int mod = (int)1e9 + 7;
int dp[N][20];
int fun(string& s,int n,int last = 11){
    if(dp[n][last] != -1)return dp[n][last];
    if(n <= 0 )return 1;
    if(s[n-1]-'0' < last){
        return dp[n][last] = (fun(s,n-1,s[n-1]-'0') + fun(s,n-1,last))%mod;
    }
    return dp[n][last]=fun(s,n-1,last);
}
int main(){
    int t;
    cin>>t;
   for(int p=1;p<=t;p++){ 
        memset(dp,-1,sizeof(dp));
        string s;
        cin>>s;
        cout<<"Case "<<p<<": "<<fun(s,s.length())-1;
        cout<<endl;
    }
}
