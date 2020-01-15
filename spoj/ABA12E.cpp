#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(){
        ll n,k;
        scanf("%lld",&n);
        scanf("%lld",&k);
        vector<long long int> arr(n+1);
        for(int i=1;i<=n;i++)cin>>arr[i];
    
        ll sum = accumulate(arr.begin()+1,arr.end(),0);
        ll low = 0,high = sum,ans=sum;
        ll mid;
        if( n == 0 ){
            cout<<"0\n";
            return 0;
        }
        while(low <= high){
            mid = (low + high)/2;
            ll curr_sum = 0;
            ll curr_rank = 0;
            int j=0;
            for(int i=1 ; i <= n;i++){
                while(j<n and curr_sum + arr[j+1] <= mid) curr_sum += arr[++j];

                if( j >= i) {
                    curr_rank += (j-i+1);
                    curr_sum -= arr[i];
                }
           }
           if( curr_rank >= k){
               ans = mid;
               high = mid - 1;
           }
           else{
               low = mid + 1;
          }
      }
        cout<<ans<<endl;
   }
