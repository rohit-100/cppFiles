#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        const int N = 10005;
        vector<int> arr1,arr2,fre1(N,0),fre2(N,0);
        for(int i=0;i<n;i++){
             int x;cin>>x;arr1.push_back(x);
             fre1[x]++;
        }
        for(int j=0;j<m;j++){
            int x;cin>>x;arr2.push_back(x);
            fre2[x]++;
        }
        long ans = 0;
        for(int i=0;i<N;i++)if(fre1[i] != 0){
            for(int j=N-1;j>0;j--)if(fre2[j] !=0 and i%j==0){
                ans += (i/j);break;
            }
        }
        cout<<ans<<endl;
    }
}
