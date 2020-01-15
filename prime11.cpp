
#include <bits/stdc++.h>
#define MAX 100050
using namespace std;
 
typedef long long ll;
vector <ll> prime;
bool arr[MAX];
bool isprime[MAX];
int main() {
	ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	
	// your code here
	for(ll i=0;i<MAX;i++){
		arr[i]=true;
	}
	arr[0]=arr[1]=false;
	for(ll i=2;i*i<MAX;i++){
		if(arr[i]==true)
		{
			for(ll j=i*i;j<MAX;j+=i)
			  arr[j]=false;
		}
	}
	prime.push_back(2);
	for(ll i=3;i<MAX;i+=2){
		if(arr[i]==true)
		  prime.push_back(i);
	}
	ll t,l,r;
	ll curprime;
	cin>>t;
	while(t--)
	{
		for(ll i=0;i<MAX;i++){
			isprime[i]=true;
		}
		cin>>l>>r;
		for(ll i=0;prime[i]*prime[i]<=r;i++){
			 curprime=prime[i];
			ll base=(l/curprime)*curprime;
			if(base<l)
			 base+=curprime;
		    for(ll j=base;j<=r;j+=curprime){
		    	isprime[j-l]=false;
		    }
		    if(base==curprime)
		      isprime[base-l]=true;
		    }
		  for(ll i=0;i<=r-l;i++){
		  	if(isprime[i]==true){
		    cout<<l+i<<endl;
		  	}
		  }

		}
 
	return 0;
}
