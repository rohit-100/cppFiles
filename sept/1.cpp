#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void multi(int arr[2][2],int ans[2][2]){
	int temp[2][2]={{1,0},{0,1}};
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			int ff=0;
			for(int k=0;k<2;k++)ff+=arr[i][k]*ans[k][j];
			temp[i][j]=ff%10;
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)arr[i][j]=temp[i][j];
	}
}
int get(ll num){
	int arr[2][2]={{1,1},{1,0}};
	int ans[2][2]={{1,0},{0,1}};
	num-=2;
	if(num==-1)return 0;
	while(num){
	
		if(num&1)multi(ans,arr);
		num>>=1;
		multi(arr,arr);
		/*for(int i=0;i<2;i++){
			for(int j=0;j<2;j++)cout<<ans[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;*/

	}
	return ans[0][0];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        ll temp=1;
       // ll ans=1;
        while(temp<=n){
              temp*=2;
        }
        temp/=2;
       // cout<<"temp = "<<temp;
        //for(int i=1;i<10;i++)
        cout<<get(temp)<<endl;
   }
}
      

