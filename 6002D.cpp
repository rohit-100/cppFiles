#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;
vector<vector<int> > g;
vector<bool> vis;
int dfs(int i){
    vis[i]=true;
    int mx = i;
    for(int val:g[i])if(!vis[val]){
        mx = max(dfs(val),mx);
    }
    return mx;
}

bool comp(const pair<int,int> a,const pair<int,int> b){
    return a.second < b.second;
}
int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,false);
    for(int i=0;i<m;i++){
        int x,y; 
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<pair<int,int> > pairs;
    for(int i=1;i<=n;i++)if(!vis[i]){
        int end = dfs(i);
        pairs.push_back({i,end});
    }
    sort(pairs.begin(),pairs.end(),comp);
    //for(int i=0;i<7;i++)cout<<pairs[i].first<<" "<<pairs[i].second<<endl;
    stack<pair<int,int> > stk;
    for(auto val:pairs)stk.push(val);
    int ans = 0;
    auto top = stk.top();
    stk.pop();
    while(!stk.empty()){
        if(stk.top().second < top.first){
            top = stk.top();
            stk.pop();
        }
        else{
            ++ans;
            auto temp = stk.top();
            stk.pop();
            top = {min(temp.first,top.first),max(temp.second,top.second)};
        }
   }
    cout<<ans<<endl;
    
}
