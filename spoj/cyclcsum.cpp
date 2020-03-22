#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

int power(int a,int b,int mod=1e9+7){
     int res = 1;
      while(b){
           if(b&1)res = 1ll*res*a%mod;
            a=1ll*a*a%mod;
            b>>=1;
      }
       return res;
} 
template<typename me>
void print(vector<me> arr){
    for(auto val:arr)cout<<val<<" ";
    cout<<endl;
}
#define inf 100000000005
struct node{
    ll left,right,ans,total;
    node(){
        left = right = ans = total = -inf;
    }
    node(int val):left(val),right(val),total(val),ans(val){}
    void merge(node a,node b){
        left = max(a.left,a.total+b.left);
        right = max(b.right,b.total+a.right);
        total = a.total + b.total;
        ans = max(a.ans,max(b.ans,a.right+b.left));
    }
};

vector<node> tree;
vi arr;
void build(int s,int ss,int se){
    if(ss > se)return ;
    if(ss == se){
        tree[s] = node(arr[ss]);
        return ;
    }
    int mid = (ss + se)>>1;

    build(s*2,ss,mid);
    build(s*2+1,mid+1,se);
    tree[s].merge(tree[s*2],tree[s*2+1]);
}
node query(int s,int ss,int se,int l,int r){
    if(se < l or r < ss)return node();
    if(l <= ss and se <= r){
        return tree[s];
    }

    int mid = (ss + se)>>1;
    node ans = node();
    node val1 = query(s*2,ss,mid,l,r);
    node val2 = query(s*2+1,mid+1,se,l,r);
    ans.merge(val1,val2);
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        arr.assign(2*n+1,0);
        tree.assign(8*n,0);
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            arr[i] = x;
            arr[i+n] = x;
        }
        build(1,1,2*n);
        for(int i=1;i<=n;i++)cout<<query(1,1,2*n,i,i+n-1).ans<<endl;

    }
}
