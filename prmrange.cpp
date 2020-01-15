#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define N 1000005
#define s second
#define f first
ll prime[N];
pair<ll,ll> tree[N];
void seive(){
	memset(prime,1,sizeof(prime));
	for(int i=2;i<N;i++)if(prime[i]){
		for(int j=2*i;j<N;j+=i)prime[j]=0;
	}
}

void build(int node,int start,int end){
	if(start == end){
		tree[node].s = 1;
		return;
	}
	int mid = (start + end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node].s = tree[2*node].s + tree[2*node +1].s;
}
void update(int node,int start,int end,int l,int r,int x){
	if(start>end || l>end || start>r)
		return;
	if(start == end){
		tree[node].s = 0;
		tree[node].f = x;
		return;
	}
	int mid = (start + end)/2;
	if(tree[2*node].s)
		update(2*node,start,mid,l,r,x);
	if(tree[2*node +1].s)
		update(2*node + 1,mid+1,end,l,r,x);
	tree[node].s = tree[2*node].s + tree[2*node +1].s;
	tree[node].f = tree[2*node].f|tree[2*node+1].f;

}
int query(int node,int start,int end,int l,int r){
	if(start>end || start>r || l>end) return 0;

	if(l<=start and r>=end)return tree[node].f;

	return query(2*node,start,(start+end)/2,l,r) | query(2*node+1,(start+end)/2+1,end,l,r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	seive();
	int k,q,n=100005;
	cin>>k>>q;
	vector<int>fact;
	int tt=k;
	for(int i=2;i<=k;i++){
		if(k%i==0 and prime[i]){
			fact.push_back(i);
			k/=i;
			i--;

		}
		if(i>sqrt(tt))break;
	}
	if(fact.size()==0)fact.push_back(k);
	sort(fact.begin(),fact.end());
	fact.erase(unique(fact.begin(),fact.end()),fact.end());
	
	while(q--){
		char s;
		int l,r,x;
		cin>>s>>l>>r;
		if(s=='?'){
			int num = query(1,1,n,l,r);
			int cnt=0;
			for(int i=0;i<32;i++){
				if(num & (1<<i))cnt++;
			}
			cout<<cnt<<"\n";
		}
		else{
			cin>>x;
			int val=0;
			for(int i=0;i<fact.size();i++){
				if(x%fact[i]==0)val=val|(1<<i);
			}
			update(1,1,n,l,r,val);
		}
	}
	return 0;
}