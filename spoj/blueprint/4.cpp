#include<bits/stdc++.h>
using namespace std;

vector<vector<long long> > dp;

long long  fun(int val,vector<int>&arr,int ind){
    if(ind < 0 or val < 0)return 1000000000;
    if(val == 0)return 0;
    if(dp[ind][val] != -1)return dp[ind][val];




    return dp[ind][val] = min(1+fun(val-arr[ind],arr,ind),fun(val,arr,ind-1));
}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        const int N = 1005;

        vector<int> arr1,arr2,fre1(N,0),fre2(N,0);
        for(int i=0;i<n;i++){
             int x;cin>>x;arr1.push_back(x);
             fre1[x]++;
        }
        for(int j=0;j<m;j++){
            int x;cin>>x;arr2.push_back(x);
            fre2[x]++;
        }

        dp.assign(arr2.size(),vector<long long >(N,-1));
        for(int i=1;i<N;i++){
            fun(i,arr2,arr2.size()-1);
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += dp[m-1][arr1[i]];
        }
        cout<<ans<<endl;
        /*
        sort(arr2.begin(),arr2.end());
        long ans = 0;
        for(int i=0;i<N;i++)if(fre1[i] != 0){
            int val = i;
            long temp = 0;
            for(int j = arr2.size()-1;j>=0 and val>0;j--){
                temp += (val/arr2[j]);
                val %= arr2[j];
            }
            ans += temp*fre1[i];
        }
        cout<<ans<<endl;
        */
    }
}
