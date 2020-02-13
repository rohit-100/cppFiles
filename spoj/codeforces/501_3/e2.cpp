#include<bits/stdc++.h>
using namespace std;

struct node{
    int left,right,up,down;
    node(char ch){
        if (ch == '.'){
            left = right = up = down = -1;
        }
        else{
            left = right = up = down = 0;
        }
    }
    node(){
        left = right = up= down = -1;
    }

};

int main(){

    int n,m;
    cin>>n>>m;
    vector<string> matrix;
    for(int i=0;i<n;i++){
        string x ;cin>>x;matrix.push_back(x);
    }
    vector<vector<node> > dp(n+2,vector<node>(m+2,'.'));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrix[i-1][j-1] == '*'){
//                 cout<<i<<" "<<j<<endl;
                dp[i][j] = node('*');
                dp[i][j].left = 1+dp[i][j-1].left;
                dp[i][j].up = 1+ dp[i-1][j].up;
            }
//             cout<<"("<<dp[i][j].left<<" "<<dp[i][j].up<<")  ";

        }
//         cout<<endl;
    }
    for(int i=n;i>0;i--){
        for(int j=m;j>0;j--){
            if(matrix[i-1][j-1] == '*'){
                dp[i][j].down =1+ dp[i+1][j].down;
                dp[i][j].right = 1+dp[i][j+1].right;
            }
//             cout<<"("<<dp[i][j].down<<" "<<dp[i][j].right<<") ";
        }
//        cout<<endl;
    }



}
