#include<bits/stdc++.h>
using namespace std;
struct node{
    int max,min;
    node(int val){
       max = val;
       min = val;
    }
    node(){

    }
};
vector<node>tree;
void input(int s,int ss,int se){
    if(ss == se){
       int val;cin>>val;
       tree[s]=node(val);
       return;
    }

    
    int mid = (ss+se)>>1;
    input(2*s,ss,mid);
    input(2*s+1,mid+1,se);
    tree[s].max = max(tree[2*s].max,tree[2*s+1].max);
    tree[s].min = min(tree[2*s].min,tree[2*s+1].min);

    
}
int get(int s,int ss,int se,int l,int r,int val){
    if(ss>se or se<l or ss>r)return 0;
    if(l<=ss and se<=r){
        if(tree[s].min > val)return (se-ss+1);
        else if(tree[s].max <= val)return 0;
        else{
            int mid = (ss+se)>>1;
            return get(s*2,ss,mid,l,r,val)+get(s*2+1,mid+1,se,l,r,val);
        }
    }
    
      int mid = (ss+se)>>1;
    return get(s*2,ss,mid,l,r,val)+get(s*2+1,mid+1,se,l,r,val);
}
int main(){
    int n;cin>>n;
    tree.resize(4*n);
    input(1,1,n);    
    int k;cin>>k;
    while(k--){
        int i,j,base;
        cin>>i>>j>>base;
        cout<<get(1,1,n,i,j,base)<<endl;
    }
}
