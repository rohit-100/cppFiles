#include <bits/stdc++.h>
using namespace std;

bool comp(pair<long long int,long long int>  a,pair<long long int,long long int> b){
	return  (double)(b.second-1)/(double)b.first < ((double)(a.second-1) / (double)a.first);
	//if(a.first != b.first)return a.first < b.first;
	
}

int main() {
	int t;
	cin>>t;
	while(t--){
		long long int n,x,a,b;
		vector<pair<long long int  ,long long int> > arr;
		cin>>n>>x;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			arr.push_back({a,b});
		}
		sort(arr.begin(),arr.end(),comp);
		
		long long ans=x;
		const int mod = 1e9 + 7;
		for(auto val:arr){
		//	cout<<val.first<<" "<<val.second<<endl;
			ans = ans*val.first +val.second;
			if(ans >= mod)ans %= mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

