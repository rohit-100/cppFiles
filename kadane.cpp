#include<bits/stdc++.h>
using namespace std;

int main(){
		int n;
		cin>>n;
		vector<int>arr(n);
		for(int i=0;i<n;i++)cin>>arr[i];
		vector<int>fwd,rev(n+1,0);
		fwd.push_back(0);
		int Max=0;
		for(int i=0;i<n;i++){
			Max+=arr[i];
			if(Max>=0)fwd.push_back(Max);
			else{
				fwd.push_back(max(0,Max));
				Max=fwd.back();
			}
		}
		Max=0;
		for(int i=n-1;i>=0;i--){
			Max+=arr[i];
			if(Max>=0)rev[i]=Max;
			else{
				rev[i]=max(Max,0);
				Max=rev[i];
			}
		}
		for(int val:fwd)cout<<val<<" ";
		cout<<endl;
		int ans=0;
		int ind=0;
		for(int i=0;i<n;i++){
			if(ans < fwd[i]+arr[i]*arr[i]+rev[i+1]){
				ans = fwd[i]+arr[i]*arr[i]+rev[i+1];
				ind=i;
			}
		}
		cout<<"ans = "<<ans<<"ind = "<<ind<<endl;
		//for(int val:rev)cout<<val<<" ";
}