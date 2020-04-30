/*
 *
 * dsu should not be implemented here
 * so giving wa
 *
 *
 *
 */




#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
const int mod = 1000000007;
typedef long long ll;
vector<int>tree[N];
vector<int>wt(N);
vector<int>dsu(N);
vector<int>size(N);
vector<int>good(N,100);
vector<int>red(N),black(N);
int t_reds=0,t_blacks=0;
vector<pair<int,int> > edges;
void dfs(int ver,int par){
    for(int to:tree[ver])if(to != par){
            dfs(to,ver);
            red[ver] += red[to];
            black[ver] += black[to];
    }
    if(wt[ver] == 1)black[ver]++;
    if(wt[ver] == 2)red[ver]++;
    if(wt[ver] == 0){
        good[ver] = 0;
        for(int to:tree[ver])if(to != par){
            if(red[to]==t_reds and black[to] == t_blacks){
                good[ver] |=0;
            }
            else good[ver] |= 1;
        }
    }
}
int power(int a,int b){
     int res = 1;
      while(b){
           if(b&1)res = 1ll*res*a%mod;
            a=1ll*a*a%mod;
            b>>=1;
      }
       return res;
} 
int find_par(int u){
    if(dsu[u] == u)return u;
    return dsu[u] = find_par(dsu[u]);
}
ll calc2(int n){

    for(int i=1;i<=n;i++)dsu[i] = i;
    for(int i=1;i<=n;i++)size[i] = 1;
    for(auto edge:edges){
       if(wt[edge.first] ==0 and  wt[edge.second]==0 and good[edge.first] == 0 and good[edge.second] == 0){
           int a = find_par(edge.first);
           int b = find_par(edge.second);
           dsu[a] = b;
           size[b] += size[a];
            
       }
    }
    for(int i=1;i<=n;i++)cout<<size[i]<<" ";
    cout<<endl;
    ll total = 0;
    for(int i=1;i<=n;i++){
        if(wt[i] == 0 and dsu[i] == i and good[i] == 0){
            total += power(2,size[i]);
            total -= 1;
            if(total >= mod)total %= mod;
            if(total < 0)total += mod;
        }
    }
    for(int i=1;i<=n;i++){
        dsu[i] = i;
        size[i] = 1;
    }
    return total;

}
ll calc(int n){

    for(int i=1;i<=n;i++)dsu[i] = i;
    for(int i=1;i<=n;i++)size[i] = 1;
    for(auto edge:edges){
       if(wt[edge.first] ==0 and  wt[edge.second]==0){
           int a = find_par(edge.first);
           int b = find_par(edge.second);
           dsu[a] = b;
           size[b] += size[a];
       }
    }
    ll total = 0;
    for(int i=1;i<=n;i++){
        if(wt[i] == 0 and dsu[i] == i){
            total += power(2,size[i]);
            total -= 1;
            if(total >= mod)total %= mod;
            if(total < 0)total += mod;
        }
    }
    for(int i=1;i<=n;i++){
        dsu[i] = i;
        size[i] = 1;
    }
    return total;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<n;i++){
            int x,y;cin>>x>>y;
            tree[x].push_back(y);
            tree[y].push_back(x);
            edges.push_back({x,y});
        }
        for(int i=1;i<=n;i++)cin>>wt[i];
        for(int i=1;i<=n;i++){
            if(wt[i] == 1)t_blacks++;
            else if(wt[i] == 2)t_reds++;
        }
//         cout<<t_reds<<" val"<<t_blacks<<endl;
        dfs(1,-1);
//         for(int i=1;i<=n;i++){
//             if(good[i] == 1)cout<<i<<" ";
// //             cout<<black[i] <<" "<<red[i]<<endl;
//         }
        cout<<endl;
        ll total = calc(n);
        total -= calc2(n);
        if(total < 0)total += mod;
        cout<<total<<endl;
        t_reds = t_blacks=0;
        for(int i=1;i<=n;i++){
            tree[i].clear();
            red[i] = 0;
            black[i] = 0;
            good[i] = 100;
            wt[i] = 0;
        }
        edges.clear();
    }
    
     
}
