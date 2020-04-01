#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;cin>>n;
    vector<vector<bool> > done(n,vector<bool>(n,false));
    vector<vector<int> > arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;cin>>x;arr[i][j]=x;
            if(x == 0)done[i][j] = true;
        }
    }
    int m;cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        --x;--y;
        if(arr[x][y] == 0 or done[x][y])continue;
        queue<pair<int,int> > q;
        q.push({x,y});
        while(!q.empty()){
            auto point = q.front();
            int a= point.first;
            int b = point.second;
            q.pop();
            done[a][b] = true;
            for(int i=-1;i<2;i++){
                for(int j = -1;j<2;j++)if((i==0 or j == 0) and i!= j  ){
                   if(a+i >=0 and a+i <n and b+j >=0 and b+j <n and done[a+i][b+j] == false){
                    q.push({a+i,b+j});
                   }
                
                }
            }
        }
    
    }

    int ans = 0 ;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(done[i][j] and arr[i][j] )++ans;
        }
    }
    cout<<ans<<endl;
}
