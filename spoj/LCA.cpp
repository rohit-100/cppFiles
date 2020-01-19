#include<bits/stdc++.h>
using namespace std;



vector<int>eular,first,height,visited;
void init(int n){
    ++n;
    eular.clear();
    first.clear();
    height.clear();
    visited.clear();
    visited.assign(n,0);
    first.resize(n);
    height.resize(n);

}
void dfs(vector<vector<int> >& tree,int val,int par,int ht){
    eular.push_back(val);
    height[val]=ht;
    first[val] = eular.size()-1;
    
    for(int v:tree[val])if(v != par){
        dfs(tree,v,val,ht+1);
        eular.push_back(val);
    }

    
}
void print(){
    
        for(int val:eular)cout<<val<<" ";
        cout<<endl;
        for(int val:first)cout<<val<<" ";
        cout<<endl;
        for(int val:height)cout<<val<<" ";
        cout<<endl;
}
vector<pair<int,int>> stree;
void insert(int s,int ss,int se,int ind,int val){
    if(ss > se)return;
    if(ss == se){
        stree[s].first=val;
        stree[s].second = eular[ind];
        return;
    }
    int mid = (se+ss)>>1;
    if(ind <= mid)insert(s*2,ss,mid,ind,val);
    else insert(s*2+1,mid+1,se,ind,val);
    if(stree[2*s].first < stree[s*2+1].first){
        stree[s] = stree[s*2];
    }
    else{
        stree[s] = stree[s*2+1];
    }
}

pair<int,int> get(int s,int ss,int se,int l,int r){
    if(ss > se or se < l or ss>r)return {10000,500};
    if(l<=ss and se <= r)return stree[s];
    int mid = (se+ss)>>1;
    return min(get(2*s,ss,mid,l,r),get(s*2+1,mid+1,se,l,r));
}
int main(){

    int t;
    cin>>t;
    for(int io=1;io<=t;io++){
        cout<<"Case "<<io<<":\n";
        int n;cin>>n;
        vector<vector<int> > tree(n+1);
        for(int i=1;i<=n;i++){
            int val;
            cin>>val;
            for(int j=0;j<val;j++){
                int mm;
                cin>>mm;
                tree[i].push_back(mm);
                tree[mm].push_back(i);
            }
        }
        /*for(int i=0;i<=n;i++){
            cout<<i<<" ---> ";
            for(int j=0;j<tree[i].size();j++)cout<<tree[i][j]<<" ";
            cout<<endl;
        }*/
        init(n);
        eular.push_back(0);
        dfs(tree,1,-1,0);

        //print();
        int m = eular.size();
        stree.clear();
        stree.resize(4*m);
        for(int i=1;i<eular.size();i++){
            insert(1,1,m,i,height[eular[i]]);
        }

        int q;
        cin>>q;
        while(q--){
           int x,y;
           cin>>x>>y;
           x=first[x];
           y=first[y];
           if(x>y)swap(x,y);
           cout<<get(1,1,m,x,y).second<<endl;
        }
    }
}
