#include<bits/stdc++.h>
using namespace std;
typedef  vector<pair<int,pair<int,int> > > vii ;
vii edges;
const int N = 100005;
vector<int>dsu(N),size(N);
int find(int ver){
    if(ver == dsu[ver])return ver;
    return dsu[ver] = find(dsu[ver]);
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edges.push_back({z,{x,y}});

    }
    for(int i=0;i<=N;i++)
    {
        dsu[i] = i;
        size[i] = 1;
    }
    sort(edges.begin(),edges.end());
    long long dp[n+1];
    memset(dp,0,sizeof(dp));
    int last = 0;
    for(int i=1;i<=n;i++){
        int a = edges[i-1].second.first;
        int b = edges[i-1].second.second;
        int wt = edges[i-1].first;
        for(int j = last+1;j<=wt;j++)dp[j]= dp[j-1];
        int pa = find(a);
        int pb = find(b);
        dp[wt] +=  1ll*size[pa]*size[pb];
        dsu[pb] = pa;
        size[pa] += size[pb];
        
        
    }
    int q;cin>>q;
    while(q--){
        int k;cin>>k;
        cout<<dp[k]<<"\n";
    }


     
}
