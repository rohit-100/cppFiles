/*
 * givin TLE 
 */






#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>dp;

int dfs(vector<string>& g,int i,int j,int dep){
//     if((char)'A'+dep != g[i][j])return 0;
    dp[i][j] = 1; 
    //cout<<g[i][j]<<endl;
    int ans = 0;
    for(int dx = -1;dx<2;dx++){
        for(int dy=-1;dy<2;dy++){
            if(dx != 0 or dy != 0){
                if(i+dx>=0 and i+dx<g.size() and j+dy>=0 and j+dy<g[0].size() and dp[i+dx][i+dy]== 0 and g[i+dx][j+dy]-'A' == dep+1)
                ans = max(ans , dfs(g,i+dx,j+dy,dep+1));
            }
        }
    }
    dp[i][j] = 0;
    return ans+1;
    
//     return dp[i][j] = ans+1;
}
int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    int Case = 1;
    int n,m;
    while(true){
//         cin>>n>>m;
        scanf("%d%d",&n,&m);
        if(n==0 and m==0)return 0;
//         cout<<"Case "<<Case<<": ";
        printf("Case %d: ",Case);
        dp.clear();
        dp.assign(n+1,vector<int>(m+1,0));
        Case++;
        vector<string>g(n);
        for(int i=0;i<n;i++){
            char ss[55];
            scanf("%s",ss);
            for(int j=0;j<m;j++)g[i].push_back(ss[j]);
        }
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<g[i].size();j++){
                if(g[i][j] == 'A'){
                    ans = max(ans,dfs(g,i,j,0));
                }
            }
        }
//          cout<<ans<<endl;
         printf("%d\n",ans);

    }

}
