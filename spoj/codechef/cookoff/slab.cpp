#include<bits/stdc++.h>
using namespace std;

typedef pair<long,long> pii;
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
    vpii arr;
    int base = 0;
    int plus = 250000;
    for(int i=0;i<7;i++){
        if(i==0)
        arr.push_back({base,base+plus});
        else arr.push_back({base+1,base+plus});
        base =base+plus;
    }
//     for(auto val:arr)cout<<val.first<<" "<<val.second<<endl;
    int t;
    cin>>t;
    while(t--){
        long n;cin>>n;
        int i=0;
        long  deduct = 0;
        for(;i<arr.size();i++){
            if(i==arr.size()-1){
                deduct +=( (n-arr[i].first+1)*1l*30)/100;
                break;
            }
            if(arr[i].first <= n){
                long val;
                val =  ((min(n,arr[i].second)-arr[i].first+1)*1l*(5*i))/100  ;
//                 cout<<val<<endl;
                deduct += val;
            }
            else break;
        }
        cout<<n-deduct<<endl;
    }
}
