#include<bits/stdc++.h>
using namespace std;
long long  power(int a,int b){
     long long  res = 1;
      while(b){
           if(b&1)res = 1ll*res*a;
            a=1ll*a*a;
            b>>=1;
      }
       return res;
} 
int main(){

    int n;cin>>n;
    vector<int>bits(32,0);
    for(int i=0;i<n;i++){
        int val;cin>>val;
        int ind = 0;
        while(val){
            if(val&1){
                bits[ind]++;
            }
            val >>= 1;
            ind++;
        }

    }
    int q;cin>>q;
    int elem = 0;
    while(q--){
        long long  ans = 0;
        int val;cin>>val;
        elem = val^elem;
        val = elem;
        int ind = 0;
        int counter = 0;
        while(counter < 32){
            if(val&1){
                ans += 1ll*(n-bits[counter])*power(2,counter);
            }
            else{
                ans += 1ll*bits[counter]*power(2,counter);
            }
            val >>= 1;
            counter++;
        }
        cout<<ans<<"\n";    
    }
}
