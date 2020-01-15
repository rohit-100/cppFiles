#include<bits/stdc++.h>
using namespaces std;
int arr[3][100005];
vector<vector<int> > tree;
int n;

long dfs(int v,int par1,int par2,int par){
    if(par2 == -1){
        long ans=;
        for(int val:tree[v])if(val != par){
            
        }
    }

}

int main(){
    cin>>n;
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++)scanf("%d",&arr[i][j]);
    }

    int x,y;
    tree.resize(n+1);
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    for(int i=0;i<=n;i++){
        if(tree[i].size()>2){
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<min(dfs(1,1,-1,-1),min(dfs(1,2,-1,-1),dfs(1,3,-1,-1)))<<endl;
    return 0;

}
