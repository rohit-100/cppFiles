#include<bits/stdc++.h>
using namespace std;
vector<int>dsu;
int par(int x){
    if(x == dsu[x])return x;
    return dsu[x] = par(dsu[x]);
}
void update(int x,int y){
    int px = par(x);
    int py = par(y);
    dsu[px] = py;
}
int main(){
    int n,m;
    cin>>n>>m;
    dsu.assign(n+1,0);
    for(int i=1;i<=n;i++)dsu[i] = i;
    bool ans = true;
    while(m--){
        int x,y;
        cin>>x>>y;
        if(par(x) == par(y))
            ans = false;
        update(x,y);
    }
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";
}
