#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int dp[n+1][k+1][2];
		memset(dp,0,sizeof(dp));
		
			dp[1][0][0]=1;
			dp[1][0][1]=1;
			/*dp[2][0][0]=2;
			dp[2][0][1]=1;
			dp[2][1][0]=0;
			dp[2][1][1]=1;*/
		
		for(int i=2;i<=n;i++){
			for(int j=0;j<=k and j<i;j++){
				dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
				dp[i][j][1]=dp[i-1][j][0];
				if(j>0)dp[i][j][1]+=dp[i-1][j-1][1];
			}
		}
		cout<<dp[n][k][0]<<" "<<dp[n][k][1]<<endl;
	}
}