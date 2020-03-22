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
void print(vi arr){
    for(int val:arr)cout<<val<<" ";
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vi a,b;
        int axor = 0;
        for(int i=0;i<n;i++){
            int x;cin>>x; 
            b.push_back(x);
        }
        for(int i=0;i<n;i++){
            int x;cin>>x;a.push_back(x); 

            axor^=x;
        }
        vi p,s;
        for(int i=0;i<n;i++){
            if(i>0)p.push_back(p.back()^b[i]);
            else p.push_back(b[i]);
        }
        s.assign(n,0);
        for(int i=n-1;i>=0;i--){
            if(i<n-1)s[i] = s[i+1]^b[i];
            else s[i] = b[i];
        }
//         print(p);
//         print(s);
        vi ans;
//         db(axor);
        for(int i=0;i<n;i++){
            int left = 0,right = 0;
            if(i>0)left = p[i-1];
            if(i<n-1) right = s[i+1];
            ans.push_back(left^right^axor);
        }
        vi anss(ans.begin(),ans.end());
        sort(a.begin(),a.end());
//         for(int val:anss)cout<<val<<" ";
//         cout<<endl;
        sort(ans.begin(),ans.end());
        bool done = true;
        for(int i=0;i<n;i++){
            if(ans[i] != a[i]){
                cout<<"-1\n";
                done = false;
                break;
            }
        }
        if(done){
            for(int val:anss)cout<<val<<" ";
            cout<<endl;
        }

        
    }
}
