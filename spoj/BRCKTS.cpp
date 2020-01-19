#include<bits/stdc++.h>
using namespace std;

struct node{
    int total,opened,closed;
    node(char ch){
        total = 0;
        if(ch == ')'){
            opened = 0;
            closed = 1;
        }
        else{
            opened = 1;
            closed = 0;
        }
    }
    node(){
        total=opened=closed=0;
    }
};
int tt;
vector<node>tree;
void add(node& c,node& a,node& b){
    c.total = a.total + b.total;
    c.opened = a.opened+b.opened;
    c.closed = b.closed+a.closed;
}
void input(int s,int ss,int se,int tt,char ch){
    if(ss == se){
    
        tree[s]= node(ch);
        //cout<<ch<<endl;
        return;
    }
    int mid = (se+ss)>>1;

    if(mid >= tt)input(s*2,ss,mid,tt,ch);
    else input(s*2+1,mid+1,se,tt,ch);
    int common = min(tree[2*s].opened,tree[2*s+1].closed);
    add(tree[s],tree[2*s],tree[2*s+1]);
    tree[s].total += 2*common;
    tree[s].opened -= common;
    tree[s].closed -= common;

}


void update(int s,int ss,int se,int ind){
    if(ss > se )return;
    if(ss == se){
        if(tree[s].opened)tree[s]=node(')');
        else tree[s] = node('(');
        return ;
    }
    int mid = (ss+se)>>1;
    if(ind <=  mid)update(s*2,ss,mid,ind);
    else update(2*s+1,mid+1,se,ind);
    int common = min(tree[2*s].opened,tree[2*s+1].closed);
    add(tree[s],tree[2*s],tree[2*s+1]);
    tree[s].total += 2*common;
    tree[s].opened -= common;
    tree[s].closed -= common;

}

void print(node a){
    cout<<a.total<<" "<<a.opened<<" "<<a.closed<<endl;

}

int main(){
    int T=1;

    int n;
    while(cin>>n){
        tree.resize(4*n);
        cout<<"Test "<<T<<":\n";
        string str;
        cin>>str;
        for(tt = 1;tt<=str.length();tt++){
            input(1,1,n,tt,str[tt-1]);
        }
        //for(node val:tree)print(val);
        int t;
        cin>>t;
        while(t--){
            int pp;
            cin>>pp;
            if(pp){
                update(1,1,n,pp);
            }
            else{
                if(tree[1].total == n)cout<<"YES";
                else cout<<"NO";
                cout<<"\n";
            }
        //    cout<<tree[1].total<<endl;
        }
        T++;
    }
}
