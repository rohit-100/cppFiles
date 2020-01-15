#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;

const int N = 1e5;
int t[2*N];
int n;
void build(){
    //cout<<"hello i am in build\n";

    for(int i=n-1;i>0;--i){
    //    cout<<"i= "<<i<<endl;
        t[i] = t[i<<1] + t[i<<1 | 1];
    }
}

void modify(int p,int val){
    for( t[p += n] = val; p>1; p>>=1) t[p>>1] = t[p] + t[p^1];
}
int query(int l,int r){
    int res = 0;
    for( l+=n , r+=n; l<r;l>>=1,r>>=1){
        if(l&1) res += t[l++];
        if(r&1) res += t[--r];
   }
    return res;
}


int main(){
    
    cin>>n;
    for(int i=0;i<n;i++)cin>>t[i+n];
   
    build();
    
    //for(int i=0;i<2*n;i++)cout<<t[i]<<" ";
    cout<<query(1,2)<<endl;
    cout<<query(2,5)<<endl;
    

}
