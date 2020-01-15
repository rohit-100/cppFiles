#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;
int get(string a){
	int res=0;
	for(int i=0;i<10;i++){
		if(a[i]=='+' or a[i]=='w')res|=(1<<i);
	}
	return res;
}

ll power(int val){
	ll base=2;
	ll res=1;
	while(val){
		if(val & 1)res*=base;
		val>>=1;
		base*=base;
		base%=mod;
		res%=mod;
	}
	return res%=mod;
}
int main(){
	//cout<<power(10)<<endl;
	int t;
	cin>>t;
	while(t--){
		//cout<<get("wbbbbbbbbbb")<<endl;

	    int fre[1025]={0};
        bool is[1025]={0};
		string x;
		cin>>x;
		int photo = get(x);
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x;
			int temp = get(x);
			is[temp]=true;
			fre[temp]++;
		}
		ll dp[2][1025];
		dp[0][photo]=1;
		int it=0;
		for(int i=0;i<1024;i++)if(is[i]){
			for(int j=0;j<1024;j++){
				dp[1-it][j^i]+=power(fre[i]-1)*dp[it][j];
				dp[1-it][j]+=power(fre[i]-1)*dp[it][j];
				
				if(dp[1-it][j^i]>=mod)dp[1-it][j^i]%=mod;
				if(dp[1-it][j]>=mod)dp[1-it][j]%=mod;

			}
			it = 1-it;


		}
		cout<<dp[it][0]<<endl;

	}
}