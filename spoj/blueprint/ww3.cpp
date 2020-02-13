#include<bits/stdc++.h>
using namespace std;
struct edge{
    int from,to,wt,ind;
    long ans;
    edge(int _from,int _to,int _wt,int _ind){
        from = _from;
        to = _to;
        wt = _wt;
        ind = _ind;
        ans = -1;
    }
};
vector<int> dsu,size;
int find(int ver){
    if(ver == dsu[ver])return ver;
    return dsu[ver] = find(dsu[ver]);
}
bool comp1(const edge& a,const edge& b){
    return a.wt < b.wt;
}
bool comp2(const edge& a,const edge& b){
    return a.ind<b.ind;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        dsu.clear();
        size.clear();
        int n;cin>>n;
        dsu.resize(n+1);
        for(int i=1;i<=n;i++)dsu[i] = i;
        size.resize(n+1,1);
        vector<edge>arr;
        for(int i=1;i<n;i++){
            int from,to,wt;
            cin>>from>>to>>wt;
            arr.push_back({from,to,wt,i});
        }
        sort(arr.begin(),arr.end(),comp1);
        for(edge& ed:arr){
            int par_a = find(ed.to);
            int par_b = find(ed.from);
            ed.ans = 1l*size[par_a]*size[par_b];
            size[par_a] += size[par_b];
            dsu[par_b] = par_a;
        } 
        sort(arr.begin(),arr.end(),comp2);
        for(edge ed:arr)cout<<ed.ans<<endl;
        
    }
     
}
