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
        int n,m;
        cin>>n>>m;
        int ans = 0;
        vi arr;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            arr.push_back(x);

        }
        ans += arr[0];
        for(int i=1;i<n;i++){
            ans +=min(m/i,arr[i]);
            m = m-i*min(m/i,arr[i]);
            if(m<=0)break;
        
        }
        cout<<ans<<endl;
    }
}
