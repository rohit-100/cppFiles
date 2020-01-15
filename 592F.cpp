#include<bits/stdc++.h>
using namespace std;

int left(int i,int n){
	return (i-1+n)%n;
}
int right(int i,int n){
	return (i+1-n)%n;
}

int main(){
	int n,k;
	cin>>n>>k;
	string str;
	cin>>str;
	vector<pair<int,int> > arr;
	int i=0,j;
	char prev = str[0];
	for(j=0;j<n;){
		if(str[j] == prev){
			j++;
			continue;
		}
		else{
			if( (j-i) > 1 ){
				arr.push_back({i,j-1});
				i=j;
				j++;
				continue;
			}
			
		}
		prev = str[j];
		i=j;
		j++;
	}
	if( (j-i) > 1 )
	arr.push_back({i,j-1});
	cout<<arr.size()<<endl;
	vector<pair<int,int> > arr1;
	for(i=0;i<arr.size();i++){
		if(i==0)arr1.push_back({0,arr[i].first-1});
		else if(i == arr.size()-1)arr1.push_back({arr[i].second + 1,n-1});
		else arr1.push_back({arr[i-1].second +1 ,arr[i].first -1 });
	}
	if(str[0] != str[n-1]){
		arr1[0].first = arr1.back().first;
		arr1.pop_back();
	}
	
		
	for(auto it:arr1){
		cout<<it.first<<" " <<it.second<<endl;
	}
}

			 
	
		
		
	
