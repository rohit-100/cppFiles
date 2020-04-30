#include<bits/stdc++.h>
using namespace std;


const int N= 100005;
vector<int>tree[N];
string str= " ";
int ans = 0;

void fun(vector<int>& mask,const vector<int>&temp){
    for(int i=0;i<26;i++)mask[i] |= temp[i];
}
vector<int> dfs(int ver,int par){
    vector<int>mask(26,0);
    for(int to:tree[ver]){
        if(to != par){
            fun(mask,dfs(to,ver));
        }
    }
    if(!mask[str[ver]-'a'])ans++;
    mask[str[ver] - 'a'] |= 1;
    return mask;
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    string temp;cin>>temp;
    str += temp;
//     cout<<str.size()<<endl;

    dfs(1,-1);
    cout<<ans<<endl;
    
      
}
