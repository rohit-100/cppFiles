#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;

const int N = 5005;
ll dp[N];

ll fun(int ind,string &s,int n){
   if( dp[ind] != -1) return dp[ind];
   if( ind >= n ) return 1;

   if(s[ind] == '0') return dp[ind] = 0;
    
   ll temp = fun(ind+1,s,n);
   int num = (10*(s[ind]-'0') + s[ind+1]-'0');
   if(ind+1 < n and num >= 1 and num <= 26)temp += fun(ind+2,s,n);
   return dp[ind] = temp;
}


int main(){
    string s;
    cin>>s;
    while(s != "0"){
        memset(dp,-1,sizeof(dp));
        int n= s.length();
        s.push_back('0');
        fun(0,s,n);
        
        if(dp[0] < 0 ){
            cout<<"0\n";
            
        }
        else
        cout<<dp[0]<<endl;
        cin>>s;
    }

    





}
/*
    if(a == '0')return -1e18; 
    if(b == '0'){
        if(((a-'0')*10 + b-'0')>27 and ind != s.size()-1)temp -= 1e18;
        temp += fun(ind + 2 , s);
    }
    else{
        temp += fun(ind + 1,s);
        if(((a-'0')*10 + b-'0')<27)temp += fun(ind + 2,s);
    }*/
