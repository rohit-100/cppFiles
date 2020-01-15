#include<bits/stdc++.h>
using namespace std;
int  main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t,n;
	cin>>t;
	while(t--){
			cin>>n;
			vector<string>arr(n);
			for(int i=0;i<n;i++)cin>>arr[i];
			int ans=INT_MAX;
			int s1=0;
			int s2=0;
			for(string s:arr){
				int t1=0;
				int t2=2;
				for(int i=0;i<s.length()/2;i++)if(s[i]=='1')t1++;
				for(int i=s.length()/2+1;i<s.length();i++)if(s[i]=='1')t2++;
				s1+=t1;
				s2+=t2;
				//ans = min(ans,2*abs(t1-t2));
			}
			ans = min(ans,abs(s1-s2));
			for(string s:arr){
				int t1=0;
				int t2=2;
				for(int i=0;i<s.length()/2;i++)if(s[i]=='1')t1++;
				for(int i=s.length()/2+1;i<s.length();i++)if(s[i]=='1')t2++;
				ans = min(ans,abs(ans-2*abs(t1-t2)));
			}
			cout<<ans<<endl;



	}

}

