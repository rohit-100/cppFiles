#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define db(x) cerr << #x << "=" << x << endl

#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl

#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

int power(int a,int b,int mod=1e9+7){
     int res = 1;
      while(b){
           if(b&1)res = 1ll*res*a%mod;
            a=1ll*a*a%mod;
            b>>=1;
      }
       return res;
} 
int main(){
     
}
