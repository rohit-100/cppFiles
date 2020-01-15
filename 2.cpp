#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > arr;
long dp[105][105][105];

long get(int k,int n,int N){
	
	if(k==0)return 0;
	if(n<0 or k<0 or N<=0)return INT_MAX;
	if(dp[n][k][N]!= -1)return dp[n][k][N];
	long ans=LONG_MAX;
	/*if(arr[n].first<= k)*/ans = min(ans,arr[n].second+get(k-arr[n].first,n,N-1));
	ans= min(ans,get(k,n-1,N));
	return dp[n][k][N]=ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,k;

	cin>>t;
	while(t-->0){
		memset(dp,-1,sizeof(dp));
		cin>>n>>k;
		for(int i=0;i<k;i++){
			int x;
			cin>>x;
			if(x!= -1)arr.push_back({i+1,x});
		}
		if(get(k,arr.size()-1,n)>=INT_MAX){
			cout<<"-1\n";
		}
		else cout<<dp[arr.size()-1][k][n]<<"\n";
		// for(int i=0;i<10;i++){
		// 	for(int j=0;j<10;j++)cout<<dp[i][j]<<" ";
		// 	cout<<endl;
		// }


	}




}