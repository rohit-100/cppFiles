#include<bits/stdc++.h>
using namespace std;

struct coin{
    int val,wt;
    coin(int val,int wt){
        this->val = val;
        this->wt =wt;
    }
    coin(){

    }
};
bool comp(const coin a,const coin b){
    return a.wt<b.wt;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int empty_wt,full_wt;
        cin>>empty_wt>>full_wt;
        int n;cin>>n;
        vector<coin>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i].val;
            cin>>arr[i].wt;
        }
        sort(arr.begin(),arr.end(),comp);
        int diff = full_wt - empty_wt;
        int dp[n+1][diff+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=diff;j++){
                if(i==0 or j==0){dp[i][j] = 100000000;continue;}
                if(i==1){
                    if(j>=arr[i].wt){
                        dp[i][j] = (j/arr[i].wt)*arr[i].val;
                    }
                    else dp[i][j] = 10000000;
                    continue;
                }
                dp[i][j] = dp[i-1][j];
                int count=0;
                for(int k=j;k>=0;k-=arr[i].wt){
                    dp[i][j] = min(dp[i][j],dp[i-1][k]+count*arr[i].val);
                    count++;
                }
            }
        }
        cout<<dp[n][diff]<<endl;

    }
     
}
