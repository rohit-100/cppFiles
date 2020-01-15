#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int>arr(n);
		for(int i=0;i<n;i++)cin>>arr[i];
		long long dp[n+1][k+2][5005];
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;

		for(int i=0;i<n;i++){
			for(int j=0;j<=k;j++){
				for(int l=0;l<5005;l++){
					if(l+arr[i-1]<5005){
						
						dp[i+1][j+1][l+arr[i]]+=dp[i][j][l];
						
					}
					dp[i+1][j][l]+=dp[i][j][l];
					//if(dp[i][j][l]){cout<<"n ="<<i<<" k="<<j<<" sum="<<l<<" fre="<<dp[i][j][l]<<endl;}

				}
			}
			//cout<<endl;
		}
		// for(int i=0;i<=n;i++){
		// 	for(int j=0;j<=k;j++){
		// 		for(int l=0;l<5005;l++)if(dp[i][j][l]){cout<<"n ="<<i<<" k="<<j<<" sum="<<l<<" fre="<<dp[i][j][l]<<endl;}
		// 	}
		// 	cout<<endl;

		// }
		for(int i=0;i<5005;i++){
			if(dp[n][k][i]){
				cout<<dp[n][k][i]<<endl;
				break;
			}
			if(i==5004){
				cout<<"0\n";
			}
		}
	}
}