#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define ALL(x) (x).begin(),(x).end()
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

int find_min_diff(vi arr){
    int total = accumulate(ALL(arr),0);
    int total_t = total;
    const int n = arr.size();
    total/=2;
    vector<bool>dp(total+1,false);
    for(int val:arr){
        vector<bool>temp(ALL(dp));
        for(int i=0;i+val<=total;i++)if( dp[i]){
            temp[i+val] = true;
            temp[i] = dp[i];
        }
        temp[val] = true;
        dp = temp;
    }
    for(int i=total;i>=0;i--){
        if(dp[i]){
            return total_t - 2*i;
        }
    }
    return 2*total; 

    
}




int main(){
      int t;
      cin>>t;
      while(t--){
          int n;cin>>n;
          string s;
          vector<int>arr;
          for(int i=0;i<n;i++){
              cin>>s;
              int total = count(ALL(s),'1');
              int left = count(s.begin(),s.begin()+n/2,'1');
              arr.push_back(abs(left - (total-left)));
              

          }
          arr = {1,3,15};
          cout<<find_min_diff(arr)<<endl;
      }
}
