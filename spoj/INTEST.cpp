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
void take(int& num){
    num = 0;
    bool isneg = false;
    int ch;
//     while((ch = getchar_unlocked())==' ');
    ch = getchar_unlocked();
    if(ch == '-'){
        isneg = true;
        ch = getchar_unlocked();
    }
    else{
//         num = ch-'0';
    }
    while(ch>='0' and ch <='9'){
        num = num<<3 + num<<1 + (ch-'0');
        ch = getchar_unlocked();
        cout<<(char)ch<<endl;

    }
    if(isneg)num = -num;

}
int readInt(){
    int res = 0;
    bool isneg = false;
    int ch;
    while(true){
        ch = getchar();
        if(ch == '-'){isneg = true;break;}
        if ( ch >= '0' and ch <='9' ){
            res = ch-'0';
            break;
        }
        
    }
    while(true){
        ch = getchar();
        if(ch >= '0' and ch <= '9'){
            res = res*10 + (ch - '0');
            continue;
        }
        else{
            break;
        }

    }
    return isneg?-res:res;

}
int main(){
        
    int n,k;
    n = readInt();
    k = readInt();
    int ans = 0;
    while(n--){
        int x = readInt();
        if( x%k == 0 )++ans;

    }
    printf("%d \n",ans);
    
}
