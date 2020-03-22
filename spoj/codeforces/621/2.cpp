#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
template<typename me>
void print(vector<me> arr){
    for(auto val:arr)cout<<val<<" ";
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,X;cin>>n>>X;
        int maxi = 0;
        bool done = false;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            maxi = max(x,maxi);
            if(x == X)done = true;
        }
        if(done){
            cout<<"1\n";
            continue;
        }
//         int ans = 0;
//         ans += ((X-1)/(2*maxi));
//         ans +=2
        int ans;
        if(maxi < X){
         ans = (X+maxi-1)/maxi;
        }
        else{ans = 2;}
        cout<<ans<<endl;
    }
}
