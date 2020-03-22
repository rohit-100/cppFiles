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
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int a,b;
        a=0;b=0;
        bool done = false;
        int aleft = n;
        int bleft = n;
        for(int i=0;i<s.length();i++){
            if(i&1){
                --bleft;
                if(s[i]-'0' >0)b++;
//                 if((b-a) >aleft ){
// //                     cout<<"hitb";
//                     cout<<i+1<<endl;
//                     done = true;
//                     break;
//                 }
            }
            else{
                --aleft;
                if(s[i]-'0' > 0)a++;
//                 if((a-b) > bleft){
// //                     cout<<"hita";
//                     cout<<i+1<<endl;
//                     done = true;
//                     break;
//                 }
//                 else if((b-a)>aleft)
            }
            if((b-a) > aleft or (a-b) > bleft){
                cout<<i+1<<endl;
                done = true;
                break;
            }

//             db2(a,b);
        }
        if(!done){
            cout<<2*n<<endl;
        }
    }
}
