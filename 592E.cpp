 #include<bits/stdc++.h>
 using namespace std;
 #define ll long long 

 int ok(vector<int> &arr,int gap){
 	vector<long>sum(arr.size(),0);
 	sum[0]=arr[0];
 	for(int i=1;i<arr.size();i++)sum[i] = sum[i-1]+arr[i];
 	
 	long minK = LONG_MAX;
 	
 	for(int i=0;i<arr.size();i++){
 		int left = arr[i]-gap;
 		int right = arr[i]+gap;
 		int left_ind,right_ind;
 		int left_val;
 		int right_val;
 		if(left <= arr[0]){
 			left_val = 0;
 		}
 		else{
 			left_ind = lower_bound(arr.begin(),arr.end(),left)-arr.begin();
 			if(arr[left_ind] != left) --left_ind;
 			left_val = sum[left_ind] - (left_ind+1)*left;
 		}
 		right_ind = lower_bound(arr.begin(),arr.end(),right)-arr.begin();
 	
 		if(right_ind >= arr.size() or arr[right_ind] == arr.back()){
 			right_val = 0;
 		}
 		else{
 			right_val = sum.back()-sum[right_ind]-(arr.size()-right_ind-1)*right;
 		}
 		if(left_val + right_val < minK)minK = left_val + right_val;
 	}
 	return minK;
 }


int ok(vector<int> &arr,int gap){
	const int n = arr.size();
	vector<long long>sum(n,0);
	sum[0]=arr[0];
	for(int i=1;i<n;i++)sum[i]=arr[i]+sum[i-1];

	vector<bool>isdone(n,false);
	int minK = INT_MAX;
	for(int i=0;i<n;i++)if(!isdone[i]){
		auto it = lower_bound(arr.begin(),arr.end(),arr[i]+gap);
		if(it != arr.end()){
			long long total = sum

		}
	}
}		
 			
 		
 			
 			
 	 
 int main(){
 
 	int n,k;
 	cin>>n>>k;
 	vector<int>arr;
 	for(int i=0;i<n;i++){
 		int x;
 		cin>>x;
		arr.push_back(x);
	}
	sort(arr.begin(),arr.end());
	
	int high = arr.back()-arr.front();
	int low = 0;
	int ans = -1;
	
	while(high >= low){
		int mid = (low + high)/2;
		
		if(ok(arr,mid)<=k){
			ans = mid;
			high = mid-1;
		}
		else {
			low = mid+1;
		}
	}
	cout<<ans<<endl;
	
}
		
