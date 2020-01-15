/* 
   in the test case 15 it is giving runtime error
   i don't know why
*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;
const int N = 2e7;
int primes[N];


void seive(){
   
    for(int i=2;i<N;i++)primes[i] = i;
    for(int i=2;i<N;i++){
        if(primes[i] == i){
            for(ll j = 1ll*i*i ; j< 1ll*N;j+=i){
                if(primes[j] == j)
                    primes[j]=i;
            }
        }
    }
}

int power(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = (1ll*res*a)%mod;
        b>>=1;
        a = (1ll*a*a)%mod;
     }
    return res;
 }
    



int main(){
    int n;
    cin>>n;
    seive();
   // for(int i=2;i<100;i++)cout<<primes[i]<<" ";
    map<int,int> gcd;
    while(n--){
        map<int,int> temp;
        int m;cin>>m;
        while(m--){
            int x; cin>>x; 
            //int freq = 1;
            while(x != 1){
                temp[primes[x]]++;
                x/=primes[x];
            }

        }
        if(gcd.size() == 0){
            gcd = temp;
           // cout<<n<<endl;
        }

        else{
            for(auto it :gcd){
                if(temp.find(it.first) != temp.end()){
                    gcd[it.first]= min(it.second,temp[it.first]);
                }
                else gcd.erase(it.first);
            }
         }
   }

    int ans = 1;
    for(auto it:gcd){
        ans = (1ll*ans*power(it.first,it.second))%mod;
    }
    cout<<ans<<endl;



    
}
