#include<bits/stdc++.h>
using namespace std;
long power(long a,long b){
     long res = 1;
      while(b){
           if(b&1)res = 1ll*res*a;
            a=a*a%10;
            b>>=1;
      }
       return res;
} 
int main(){

    long t;
    cin>>t;
    while(t--){
        long n,m;
        cin>>n>>m;
        cout<<power(n,m)%10<<endl;
    }
}
