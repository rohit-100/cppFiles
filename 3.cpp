#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int t,n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		int p[k+1];
		for(int i=1;i<=k;i++)scanf("%d",p+i);

		long ans[k+1];
		for(int i=0;i<=k;i++)ans[i]=INT_MAX;
		
		ans[0]=0;
		for(int i=1;i<=k;i++){
			for(int j=0;j<i;j++){
				if(p[i-j] != -1 and ans[j] != -1){
					ans[i]=min(ans[i],ans[j]+p[i-j]);
				}
			}
		}
		if(ans[k]>=INT_MAX)cout<<"-1\n";
		else cout<<ans[k]<<endl;
		//for(int i=1;i<=k;i++)cout<<ans[i]<<" ";
		
	}
}