#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;

    const int N = 100005;
    bitset<N> bs[2];
    int jj=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        bs[jj]|=1;
        bs[1-jj] = bs[jj] | bs[jj] << x;
        jj = 1-jj;
    }
    //jj = 1-jj;
    int s[N]={0};
    for(int i=1;i<=N;i++){
        s[i]=s[i-1] + bs[jj][i];
   }
    while(q--){
        int e,b;
        cin>>b>>e;
        cout<<s[e]-s[b-1]<<"\n";
    }
 }
