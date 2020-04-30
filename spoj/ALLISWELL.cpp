#include<bits/stdc++.h>
using namespace std;
int t,r,c;
vector<string> graph;
const int N = 105;
int dp[N][N];
bool issafe(int i,int j){
    return i>=0 and i<r and j>=0 and j<c;
}
const char* str = "ALLIZZWELL";
bool dfs(int i,int j,int dep=0){
//     if(dep == 10)return true;
//     dp[i][j] = 1;
//     bool ans = false;
//     for(int dx =-1;dx<2;dx++){
//         for(int dy=-1;dy<2;dy++)if(dx !=0 or dy != 0){
//             if(issafe(i+dx,j+dy) and !dp[i+dx][j+dy] and str[dep] == graph[i+dx][j+dy])
//                ans |= dfs(i+dx,j+dy,dep+1);
//         }
//     }
//     dp[i][j] = 0;
//     return ans;
       if( !issafe(i,j) or dp[i][j] )return false;
       if(str[dep] != graph[i][j])return false;
       if(dep >= 9)return true;
       dp[i][j] = 1;
       bool ans = false;
       for(int dx =-1;dx<2;dx++){
           for(int dy=-1;dy<2;dy++)if(dx !=0 or dy != 0){
               ans |= dfs(i+dx,j+dy,dep+1);
            

           }
       }
       dp[i][j] = 0;
       return ans;
}
       
int main(){

    cin>>t;
    while(t--){
        graph.clear();
        cin>>r>>c;
        for(int i =0;i<r;i++){
            string temp;cin>>temp;
            graph.push_back(temp);
        }
        bool founded = false;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)if(graph[i][j] == 'A'){
                if(dfs(i,j)){
                    founded = true;
                    cout<<"YES\n";
                }
            }
        }
        if(!founded)cout<<"NO\n";

    }
}
