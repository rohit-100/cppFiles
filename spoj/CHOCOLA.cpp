#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        priority_queue<pair<int,int> > pq;
        int xt=0,yt=0;
        for(int i=1;i<n;i++){
            int x; cin>>x;pq.push({x,0});
            xt += x;
        }
        for(int j=1;j<m;j++){
            int y;cin>>y;pq.push({y,1});
            yt += y;
        }
        long long ans = 0;
        int px = 1,py = 1;
        while( !pq.empty() ){
            auto top = pq.top();
            pq.pop();
            if(top.second == 0){
                ans += 1ll*py*top.first;
                ++px;
                continue;
            }
            ans += 1ll*px*top.first;
            ++py;
            
        }
        cout<<ans<<endl;

    }
}
