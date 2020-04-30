#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int>tree[N];
int wt[N];
vector<pair<int,int> > dp(N);
const int inf = 1000000007;
int ans = 0;
void dfs(int ver,int par){
    dp[ver].first = dp[ver].second = wt[ver];
    for(int to:tree[ver])if(to != par){
        dfs(to,ver);
        dp[ver].first = min(dp[ver].first,dp[to].first);
        dp[ver].second = max(dp[ver].second,dp[to].second);
        ans = max(ans,max(abs(dp[to].first-wt[ver]),abs(dp[to].second-wt[ver])));
    }

}
void print(int n){
    for(int i=1;i<=n;i++){
        cout<<dp[i].first<<" "<<dp[i].second<<endl;
    }
}
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>wt[i]; 
    }
    int root;
    for(int i=1;i<=n;i++){

        int x;cin>>x;
        if(x == -1){
            root =i;
            continue;
        }
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    for(int i=1;i<=n;i++){
        dp[i].first = inf;
        dp[i].second = -inf;
    }
    dfs(root,-1);
//     print(n);
    cout<<ans<<endl;


     
}
