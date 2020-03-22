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

vector<ll>  tree,arr;
void build(int s,int ss,int se){
    if(ss > se)return ;
    if(ss == se){
        tree[s] = arr[se];
        return; 
    }
    int mid = (ss + se)>>1;
    build(s*2,ss,mid);
    build(s*2+1,mid+1,se);
    ll ans = 0;
    if (tree[2*s] >=0)ans += tree[2*s];
    if(tree[2*s +1] >=0) ans += tree[2*s+1];
    if(tree[s*2] <0 and tree[2*s+1]< 0){
        tree[s] = max(tree[2*s] , tree[2*s+1]);
        return ;
    }
    tree[s] = ans;
}
ll query(int s,int ss,int se,int l,int r){
    if(se < l or ss > r)return -1000000000005; 
    if(l<=ss and se<=r){
        return tree[s];
    }
    int mid = (ss+se)>>1;
    return query(s*2,ss,mid,l,r)+query(s*2+1,mid+1,se,l,r);
}

int main(){


    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        arr.assign(2*n+1,0);
        tree.assign(4*n,0);
        for(int i=1;i<=n;i++){cin>>arr[i];arr[i+n] = arr[i];}
        for(int val:arr)cout<<val<<" ";
        cout<<endl;
        build(1,1,n*2);
        for(int i=1;i<=n;i++)cout<<query(1,1,n*2,i,i+n-1)<<endl;
    }
     
}
