#include<bits/stdc++.h>
using namespace std;
const int mod =998244353;



void multiply(int res[][2],int mat[][2]){
    int ans[2][2] = {{1,0},{0,1}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            long long sum = 0;
            for(int k=0;k<2;k++){
                sum += 1ll*res[i][k]*mat[k][j];
                if(sum >= mod)sum%=mod;
            }
            ans[i][j] = sum;

        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)res[i][j] = ans[i][j];
    }
}

int getfab(int n,int a,int b,int e,int f){
    if(n == 0)return a;
    if(n == 1) return b;
    int mat[2][2] = {{e,f},{1,0}};
    n = n-1;
    int res[2][2] = {{1,0},{0,1}};
    while(n){
        if(n&1)multiply(res,mat);
        n >>= 1;
        multiply(mat,mat);
    }
    return (1ll*res[0][0]*b%mod + 1ll*res[0][1]*a%mod)%mod;
}
long getxs(int n,int c,int d){
    long  arr[] = {c,d,c^d};
    
    return arr[n%3];
}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,a,b,c,d,e,f;cin>>n>>a>>b>>c>>d>>e>>f;
        int fab = getfab(n,a,b,e,f);
//         cout<<"fab = "<<fab<<endl;

        long xs = getxs(n,c,d);
//         cout<<"xs = "<<xs<<endl;
        cout<<  1ll*fab*xs + fab - xs<<endl;
//            for(int i=0;i<5;i++)cout<<getfab(i,a,b,e,f)<<" ";
    }
}
