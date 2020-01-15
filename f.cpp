#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>p(n),q(n);
	for(int i=0;i<n;i++)cin>>p[i];
	for(int i=0;i<n;i++)cin>>q[i];

	set<int>sp;
	vector<int>ans;
	int j,i;
	i=0;
	for(j=0;j<n;j++){
			if(sp.count(p[j]))sp.erase(p[j]);
				else sp.insert(p[j]);
			if(sp.count(q[j]))sp.erase(q[j]);
				else sp.insert(q[j]);
			
			if(sp.empty()){
				ans.push_back(j-i+1); // storing the length of substring in which same char will present in ans
				i=j+1;
			}
			
		
			
		}
	if(ans.size()>=k){cout<<"YES\n";
	string res="";
	char base='a';
	for(int val:ans){
		for(int i=0;i<val;i++)res.push_back(base);
		base++;
		if(base>'z')base--;
	}
	cout<<res<<endl;
	}else cout<<"NO\n";

}
