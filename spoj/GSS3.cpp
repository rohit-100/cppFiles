#include<bits/stdc++.h>
using namespace std;
const int N = 4*50000;

long n;
struct node{
    long ps,ss,ts,ans;
    node(long val){
        ans = val;
        ts = val;
        if(val > 0){
            ps = val;
            ss = val;
        }
        else{
            ps = 0;
            ss = 0;
        }
    }
    node(){
        ps = 0;
        ss=0;
        ts = 0;
        ans =0;
    }
};
node tree[N];
void merge(node tree[],long s){
    long l = 2*s;
    long r = 2*s+1;
    tree[s].ts = tree[l].ts + tree[r].ts;
    tree[s].ps = max (tree[l].ts + tree[r].ps,tree[l].ps);
    tree[s].ss = max(tree[l].ss + tree[r].ts , tree[r].ss);
    tree[s].ans = max(tree[l].ans , max(tree[r].ans , tree[l].ss + tree[r].ps));
}
void update(long s,long ss,long se,long ind,long val){
    if(ss > se or ind < ss or ind > se )return;
    if(ss == ind){
        tree[s]=node(val);
        return;
    }
    long mid = (ss + se)>>1;
    update(s*2,ss,mid,ind,val);
    update(s*2+1,mid+1,se,ind,val);
    merge(tree,s);
}

long getans(long s,long ss,long se,long p,long q){
    if(se < p or q < ss or p> q) return -1e13;
    if(p<=ss and q>=se){
        return tree[s].ans;
    }
    long mid = (ss + se)>>1;
    return max(getans(s*2,ss,mid,p,q),getans(2*s+1,mid+1,se,p,q));
}


int main(){
    vector<long>arr;
    cin>>n;
    for(long i=0;i<n;i++){
         long x;
         cin>>x;
         update(1,1,n,i+1,x);
    }
    long q;
    cin>>q;
    while(q--){
       long type;
       cin>>type;
       if(type == 0){
           long x,y;
           cin>>x>>y;
           update(1,1,n,x,y);
       }
       else{
           long x,y;
           cin>>x>>y;
           cout<<getans(1,1,n,x,y)<<endl;
       }
   }
}
