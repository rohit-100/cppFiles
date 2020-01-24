#include<bits/stdc++.h>
using namespace std;

vector<int>tree,lazy;

void update(int s,int ss,int se,int l,int r){
    if(ss>se)return ;
    if(lazy[s]){
        tree[s] = (se-ss+1)-tree[s];
        if(ss != se){
            lazy[s*2] = 1-lazy[s*2];
            lazy[s*2+1] = 1-lazy[s*2+1];
        }
        lazy[s] = 0;
    }
    if(se < l or r < ss)return ;
    if(l <= ss and se <= r){
        tree[s] = (se-ss+1)-tree[s];
        if(ss != se){
            lazy[s*2] = 1-lazy[2*s];
            lazy[s*2+1] = 1-lazy[2*s+1];
        }
        return ;
    }
    int mid = (ss+se)>>1;
    update(s*2,ss,mid,l,r);
    update(s*2+1,mid+1,se,l,r);
    tree[s] = tree[s*2]+tree[s*2+1];
}

int get(int s,int ss,int se,int l,int r){
    if(ss > se)return 0;
    if(lazy[s]){
        tree[s] = (se-ss+1)-tree[s];
        if(ss != se){
            lazy[s*2] = 1-lazy[s*2];
            lazy[s*2+1] = 1-lazy[s*2+1];
        }
        lazy[s] = 0;

    }
    if(se < l or ss > r)return 0;
    if(l<=ss and se<=r)return tree[s];
    int mid = (ss+se)>>1;
    return get(s*2,ss,mid,l,r) + get(s*2+1,mid+1,se,l,r);
}
int main(){

    int n,q;cin>>n>>q;
    tree.clear();
    tree.resize(4*n,0);
    lazy.clear();
    lazy.resize(4*n,0);
    //build(1,1,n);
    while(q--){
        int type;cin>>type;
        if(type == 0){
            int l,r;cin>>l>>r;
            update(1,1,n,l,r);
        }

        else{
            int l,r;cin>>l>>r;
            cout<<get(1,1,n,l,r)<<endl;
        }
        
//        for(int val:tree)cout<<val<<" ";
//        cout<<endl;
    }
}
