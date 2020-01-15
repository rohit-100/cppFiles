#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1e9+7
int main(){
	int n,k;
	cin>>n>>k;
	if(k==1){
		cout<<"0\n";
		return 0;
	}
	vector<int>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr.begin(),arr.end());
	const int N=200005;
	vector<int>fre(N,0);
	vector<int>step(N,0);
	int ans = INT_MAX;
	for(int i=0;i<n;i++){
		int val = arr[i];
		int steps = 0;
		fre[val]++;
		if(fre[val]>=k)ans = min(ans,step[val]);
		while(val!=0){
			val/=2;
			steps++;
			fre[val]++;
			step[val]+=steps;
			if(fre[val]>=k)ans = min(ans,step[val]);
		}
	}
	cout<<ans;


}