#include<bits/stdc++.h>
using namespace std;


template<typename A,typename B>
B find_par( A& par,B val){
    if(par[val] == val)return val;
    return par[val] = find_par(par,par[val]);
}
int main(){

    int n,m;cin>>n>>m;
    vector<int>par(n);
    for(int i=0;i<n;i++)par[i] = i;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        int par_a = find_par(par,a);
        int par_b = find_par(par,b);
        par[par_a] = par_b;
    }
    set<int>pars;
    for(int i=0;i<n;i++){
        pars.insert(find_par(par,i));

    }
    cout<<pars.size()<<endl;

}
