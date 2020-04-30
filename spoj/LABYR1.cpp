#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<string>graph;
pair<int,int> delta[] = {{-1,0},{1,0},{0,-1},{0,1}};
#define f first
#define s second
vector<vector<int> > dp;
int ans = 0; 
bool issafe(int i,int j){
    return i>=0 and i<n and j>=0 and j<m;
}

int x,y,mx=0,length=0;


void dfs(int i,int j){
    cout<<i<<" "<<j<<graph[i][j]<<endl;
    dp[i][j]= 1;
    length++;
    if(length > mx){
        mx = length;
        x = i;
        y=j;
    }
    for(auto del:delta){
        int dx = del.f;
        int dy = del.s;
        if(issafe(i+dx,j+dy) and !dp[i+dx][j+dy] and graph[i+dx][j+dy] == '.'){
            dfs(i+dx,j+dy);
        }
    }
    length--;
}
int main(){

    int t;
    cin>>t;
    while(t--){
        ans = 0;
        graph.clear();
        cin>>m>>n;
        dp.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            string temp;cin>>temp;
            graph.push_back(temp);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(graph[i][j] == '.' and !dp[i][j]){
                    dfs(i,j); 
                }   
            }
        }
        cout<<x<<" "<<y<<endl;
        dfs(x,y);
        cout<<"Maximum rope length is "<<mx-1<<"."<<endl;
        dp.clear();
        length=0;
        mx = 0;

    }
}
















































// #include<bits/stdc++.h>
// using namespace std;
// 
// bool issafe(int i,int j,int n,int m){
//     if(i>=0 and i<n and j>=0 and j<m)return true;
//     return false;
// }
// int dfs(vector<string>& graph,vector<vector<bool> >& done,int i,int j){
//     int ans = 1;
//     done[i][j] = true;
//     for(int dx = -1;dx<2;dx++){
//         for(int dy = -1;dy<2;dy++){
//             if(dx ==0 or dy == 0){
//                 if(issafe(i+dx,j+dy,graph.size(),graph[0].size())){
//                     if(!done[i+dx][j+dy]){
//                         ans = max(ans,dfs(graph,done,i+dx,j+dy));
// 
//                     }
//                     else ans = max()
//                     
//             }
//         }
//     }
//     }
//     return ans;
// }
// 
// 
// int main(){
// 
//     int n,m;
//     cin>>m>>n;
//     
//     vector<string> graph(n);
//     for(int i=0;i<n;i++)cin>>graph[i];
// 
//     vector<vector<bool> > done(n,vector<bool>(m,false));
// 
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<graph[i].length();j++){
//             if(!done[i][j] and g[i][j] == '.')
//                 ans = max(ans,dfs(g,done,i,j));
//             
//         }
//     }
// }
