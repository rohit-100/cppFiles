#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		long sum=0;
		vector<int>arr;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			sum+=x;
			arr.push_back(x);
		}
		if(sum%k!=0){
			cout<<"no\n";
			arr.clear();
			continue;
		}
		long x=sum/k;
		bool dp[k+1][(1<<n)];
		memset(dp,false,sizeof(dp));
		dp[0][0]=true;
		int count=0;
		for(int i=0;i<k;i++){
			for(int j=0;j<(1ll<<n);j++){
				if(!dp[i][j])continue;
				long temp=0;
				for(int kk=0;kk<n;kk++){
					if(j & (1ll<<kk)) //continue;
					temp += arr[kk];
				}
				temp -= (i*x);
				for(int kk=0;kk<n;kk++){
					if(j & (1ll<<kk))continue;
					if(temp + arr[kk] == x)dp[i+1][j|(1ll<<kk)]=true;
					else if(temp + arr[kk]<x)dp[i][j|(1ll<<kk)]=true;
				}
				count++;

			}

		}
		if(dp[k][(1<<n)-1])cout<<"yes\n";
		else cout<<"no\n";

	}
}