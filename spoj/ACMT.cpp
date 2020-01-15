#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;

int main(){
      int t;
      cin>>t;
      while(t--){
          int e,n;
          cin>>e>>n;
          if(e >= 2*n or n >= 2*e ){
              cout<< min(e,n)<<endl;
              continue;
          }
          if(n>e)swap(e,n);
          cout<<(e-n)+(4*n - 2*e)/3<<endl;
     }






}
