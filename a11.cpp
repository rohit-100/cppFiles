#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int s,i,k;
		cin>>s>>i>>k;
		float v=float(i-s+k)/2;
		v < 0 ? cout<<k+1<<endl:cout<<k-(i-s+k)/2<<endl;
	}
}