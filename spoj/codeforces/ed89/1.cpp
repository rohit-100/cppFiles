#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<vector<int> > arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        int ans = 0;
        map<int,pair<int,int> > mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]){
                    mp[i+j].first++;
                }
                else mp[i+j].second++;
            }
        }
        int total = n+m-2;
        for(int dist = 0;;dist++){
           if(dist >= total-dist)break;
           int ones = mp[dist].first;
           ones += mp[total-dist].first;
           int zeros = mp[dist].second;
           zeros += mp[total-dist].second;
           ans += min(ones,zeros);
        }
        cout<<ans<<endl;
    }
}
