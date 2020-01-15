#include<bits/stdc++.h>
using namespace std;
int n,s;
int a[105],b[105],c[105];
int get(int ind,int ss,int pp){
	if(ind<0 and ss>=0 and pp>0)return 1;
	if(ind < 0 or  ss<0 )return 0;
	return get(ind,ss-a[ind],pp-b[ind]+c[ind]) + get(ind-1,ss,pp);
}
int main(){
	int t;
	
	cin>>t;
	while(t--){
		cin>>n>>s;
		for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
		//for(int i=0;i<n;i++)cout<<c[i]<<" ";

		cout<<get(n-1,s,0);
	}
}