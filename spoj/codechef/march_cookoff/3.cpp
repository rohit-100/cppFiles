#include<bits/stdc++.h>
using namespace std;
long long  power(long long int a,long long  b,int mod=1e9+7){
     long long  res = 1;
      while(b){
           if(b&1)res = 1ll*res*a%mod;
            a=1ll*a*a%mod;
            b>>=1;
      }
       return res%mod;
} 
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<vector<int> > arr(n,vector<int>(32,0));
        bool flag = false;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            int ind = 0;
            if(i>0){
            for(int j=0;j<32;j++)
                arr[i][j] = arr[i-1][j];
            }
             
            while(32-ind){
                if(x&1){
                    arr[i][ind] = 1;
                }
                else{

                    if (i>0 and arr[i][ind] == 1){
                        flag = true;
                    }
                }
                x>>=1;
                ++ind;
            }
        }
        if(flag){
            cout<<"0\n";
            continue;
        }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<32;j++)cout<<arr[i][j];
//             cout<<endl;
//         }
        const int mod = 1000000007;
        long long ans = 0;
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
                if(arr[j][i]){
                    ans += (n-j-1);
                    if(ans >= mod)ans %= mod;
                    break;
                }
            }
        }
        cout<<power(2,ans)<<endl;

    }
}
