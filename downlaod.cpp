#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int  reduce(stack<pii> &st){
	if(st.empty())return 0;
	//if(st.size() == 1)return st.top().second - st.top().first + 1;
	pii temp = st.top();
	st.pop();
	int ans=0;
	while(!st.empty()){
		if(st.top().second >= temp.first){
			pii tt = st.top();
			st.pop();
			temp = {tt.first,max(tt.second,temp.second)};
		}
		else {
			ans+=(temp.second - temp.first +1);
			temp = st.top();
			st.pop();
		}

	}
	return ans + temp.second - temp.first +1;
}
int main(){

	int n;
	cin>>n;
	vector<pii> arr;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		arr.push_back({x,y});
	}
	sort(arr.begin(),arr.end());
	int q;
	cin>>q;
	while(q--){
		int  k;
		cin>>k;
		vector<pii>ss;
		for(int i=0;i<k;i++){
			int v;
			cin>>v;
			int high = n-1;
			int low =0;
			int mid;
			int ans1 = n;
			while(low <= high){
				mid = (low + high)/2;
				if(arr[mid].second >= v){
					ans1=mid;
					high = mid-1;
				}
				else{
					low=mid+1;
				}
			}

			 high = n-1;
			 low =0;
			 mid;
			int ans2 = n;
			while(low <= high){
				mid = (low + high)/2;
				if(arr[mid].first > v){
					ans2=mid;
					high=mid-1;
				}
				else{
					low=mid+1;
				}
			}
			if(ans1 != ans2){
				ss.push_back({ans1,ans2-1});
			}
			//cout<<"ans1 = "<<ans1<<" ans2= "<<ans2<<endl;

		}
		sort(ss.begin(),ss.end());

		stack<pii>st;
		for(pii val:ss){
			cout<<val.first<<" "<<val.second<<"    ";
			st.push(val);
		}
		//cout<<endl;
		cout<<reduce(st)<<endl;
	}
}