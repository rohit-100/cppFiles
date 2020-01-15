#include<bits/stdc++.h>
using namespace std;

int main(){


	int t;
	cin>>t;
	while(t--){
		int n,x;	
		cin>>n>>x;
		int ans=0;
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			ans = max(ans,a-b);
		}
		if(ans==0){
			puts("-1");
		}
		else{
			cout<<(ans+x-1)/ans<<endl;
		}
	}
}