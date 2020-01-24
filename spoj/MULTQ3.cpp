#include<bits/stdc++.h>
using namespace std;
struct node{
    int zero,one,two;
    node(){
        zero = 1;
        one = 0;
        two = 0;
    }
    node(int val){
        zero = 0;
        one = 0;
        two = 0;
    }
    node operator+(node a){
        node res;
        res.zero =zero +  a.zero;
        res.one = one +a.one;
        res.two = two +a.two;
        return res;
    }
};
void rotate(node& p){
    int temp = p.zero;
    p.zero = p.two;
    p.two = p.one;
    p.one = temp;
    //temp = p.one;
    //p.two  = p.zero;
    //p.two = temp;
}
void add(node& p,int val){
    for(int i=0;i<val;i++)rotate(p);
}
vector<node>tree;
vector<int>lazy;

void update(int s,int ss,int se,int l,int r){
    //cout<<ss<<" "<<se<<" "<<l<<" "<<r<<endl;
    if(l>r or se < l or ss>r)return ;
    
    
    if(lazy[s] != 0){
        add(tree[s],(lazy[s]*(se-ss+1))%3);
        if(ss != se){
            lazy[2*s] += lazy[s];
            lazy[2*s+1] += lazy[s];
            
        }
        lazy[s] = 0;
        
    }
    if(l <= ss and se <= r){
        add(tree[s],(se-ss+1)%3);
        if(ss != se){
            lazy[2*s] += 1;
            lazy[2*s+1] += 1;
            
        }
        return;

        
    }
    int mid = (ss + se)>>1;
    update(s*2,ss,mid,l,r);
    update(s*2+1,mid+1,se,l,r);
    tree[s] = tree[s*2]+tree[s*2+1];
}


node get(int s,int ss,int se,int l ,int r){
    //cout<<ss<<" "<<se<<" "<<l<<" "<<r<<endl;
    if(ss > se or se < l or r<ss)return node(0);
    if(lazy[s] != 0){
        add(tree[s],(lazy[s]*(se-ss+1))%3);
        if(ss != se){
            lazy[2*s] += lazy[s];
            lazy[2*s+1] += lazy[s];
            
        }
        lazy[s] = 0;
        
    }
    if(l <= ss and se <= r){
        return tree[s];
    }
    int mid = (ss + se)>>1;
    return get(s*2,ss,mid,l,r)+get(s*2+1,mid+1,se,l,r);
}
void build(int s,int ss,int se){
    if(ss > se)return;
    if(ss == se){
        tree[s] = node();
        return;
    }
    int mid  = (ss + se)>>1;
    build(s*2,ss,mid);
    build(s*2+1,mid+1,se);
    tree[s] = tree[s*2] + tree[s*2+1];
}

int main(){

    int n,q;cin>>n>>q;
    vector<int>arr(n+1);
    //for(int i=1;i<=n;i++)cin>>arr[i];
    tree.resize(4*n+4);
    lazy.resize(4*n+4,0);
    //cout<<tree[1].zero<<endl;
    build(1,1,n);
    //for(auto val:tree)cout<<val.zero<<" ";
    while(q--){
        int type;cin>>type;
        if(type == 0){
            int x,y;cin>>x>>y;
            ++x;++y;
            update(1,1,n,x,y);
        }
        else{
            int x,y;cin>>x>>y;
            ++x;++y;
            //cout<<x<<" "<<y<<endl;
            cout<<get(1,1,n,x,y).zero<<endl;
        }
        //for(auto val:tree)cout<<val.zero<<" ";
        //cout<<endl;
        //for(int val:lazy)cout<<val<<" ";
        //cout<<endl;
    }


}
