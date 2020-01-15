#include<iostream>
#include<cstring>

using namespace std;

const int MAX = 2050;
int cost[MAX];
int dp[MAX][MAX];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i='a';i<='z';i++)cin>>cost[i];
    string a,b;
    cin>>a;
    cin>>b;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1]+cost[a[i-1]];
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][m]<<endl;
}
