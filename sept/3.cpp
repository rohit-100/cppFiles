#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>fre(10005,0);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		fre[x]++;
	}
	vector<pair<int,int> >arr;
	for(int i=0;i<10005;i++)if(fre[i])arr.push_back({i,fre[i]});
	const int mod = 1e9+7;
	typedef long long ll;
	ll dp[10005];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=arr.size();i++){
		int ff = arr[i-1].second;
		for(int j=i;j>0;j--){
			dp[j]+=ff*dp[j-1];
			if(dp[j]>=mod)dp[j]%=mod;
		}
	}
	ll ans=0;
	for(int i=0;i<=k;i++){
		ans+=dp[i];
		if(ans>=mod)ans%=mod;
	}
	cout<<ans<<endl;

}