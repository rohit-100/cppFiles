#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
#define N 1005
bool vis[N][N];
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            vis[i][j] = false;
        }
    }
}
bool safe(int i,int j){
    return i>=0 and j>=0 and i<n and j<m;
}

int dfs(int x,int y,vector<string>& g){
    int ans = 1;
    vis[x][y] = true;
    for(int i=-1;i<2;i++){
        for(int j = -1;j<2;j++)if(i*i + j*j == 1){
            if(safe(x+i,y+j) and g[x+i][y+j] == '#' and  !vis[x+i][y+j])
               ans +=  dfs(x+i,y+j,g);
        }
    }
    return ans;
}
ll ggcd(ll a,ll b){
    if(b == 0)return a;
    return ggcd(b,a%b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        init();
        cin>>n>>m;
        vector<string>g(n);
        for(int i=0;i<n;i++)cin>>g[i];

        ll p = 0;
        ll q = 1ll*m*n;
        for(int i=0;i<n;i++){
            for(int j=0;j<g[i].length();j++){
                if(g[i][j] == '#' and !vis[i][j]){
                    ll cnt = dfs(i,j,g);
                    p += cnt*cnt;
                }
            }
        }
        ll gcd = ggcd(p,q);
        p/=gcd;
        q/=gcd;
        cout<<p;
        if( q != 1){
            cout<<" / "<<q<<endl;
        }else
            cout<<endl;


        /*for(string s:g){
            for(char ch:s){
                cout<<ch;
            }
            cout<<endl;
        }
        cout<<endl;
        */
    }
}
