#include<bits/stdc++.h>
using namespace std;
#define N 5003
typedef long long ll;
ll dp[N][N];
ll inf = 1e18;
int a[N];
int b[N];
int n;
ll get(int i,int j,int p){
	if(i>n and j>n)return 0;
	ll f1=a[i];
	ll f2=b[j];
	if(p==1){
		if(dp[i][j]!=inf)return dp[i][j];
		dp[i][j]= -inf;
		if(i<=n){
			dp[i][j]=max(dp[i][j],f1+get(i+1,j,2));
		}
		if(j<=n){
			dp[i][j]=max(dp[i][j],f2+get(i,j+1,2));
		}
	}
	else{
		if(dp[i][j]!=inf)return dp[i][j];
		dp[i][j]= inf;
		if(i<=n){
			dp[i][j]=min(dp[i][j],-f1+get(i+1,j,1));
		}
		if(j<=n){
			dp[i][j]=min(dp[i][j],-f2+get(i,j+1,1));
		}
	}
	return dp[i][j];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)dp[i][j]=inf;
	}
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	cout<<get(1,1,1);

}