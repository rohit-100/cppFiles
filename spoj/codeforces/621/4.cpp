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
vector<vi> g;
vi spe;
vi dist;
vector<bool> done;
void bfs(int src){
    queue<pii> q;
    q.push({src,0});
    while(!q.empty()){
        auto val = q.front();
        q.pop();
        done[val.first] = true;
        dist[val.first] = val.second;
        for(int vv:g[val.first])if(!done[vv]){
            q.push({vv,val.second+1});
        }
        
    }
}
int fun(vi dist){
    int val = dist[0];
    int ind = 0;
    for(int i=1;i<dist.size();i++){
        if(binary_search(spe.begin(),spe.end(),i) and dist[i] > val){
            val = dist[i];
            ind = i;
        }
    }
    return ind;
}
int fun(vi dist,int nottake){
    int val = -1;
    int ind = -1;
    for(int i=0;i<dist.size();i++){
        if(binary_search(spe.begin(),spe.end(),i) and i!= nottake and dist[i] > val){
            val = dist[i];
            ind = i;
        }
    }
    return ind;
}
int main(){
    int n,m,k;cin>>n>>m>>k;
    g.resize(n+1);
    dist.assign(n+1,0);
    done.assign(n+1,false);
    for(int i=0;i<k;i++){
        int x;cin>>x;//if(x != 1 and x != n)
            spe.push_back(x);
    }
    sort(spe.begin(),spe.end());
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans ;   
    bfs(1);
    ans = dist[n];
//     db(ans);
    if(spe.size() ==0){
        cout<<ans<<"\n";
        exit(0);
    }
    vi dist1 = dist;
    dist.assign(n+1,0);
    done.assign(n+1,false);
    bfs(n);
    vi distn = dist;
    int aa = fun(dist1);
//     db(dist1[aa]);
    
    int bb = fun(distn,aa);
//     db(distn[bb]);
//     db(aa);
//     db(bb);
    if(ans < dist1[aa] + distn[bb]){
        swap(aa,bb);
    }
//     db(aa);
//     db(bb);
//     db(dist1[aa]);
//     db(distn[bb]);
    ans = INT_MAX;
    vpii dists;
    for(int i=0;i<spe.size();i++){
        dists.push_back(distn[spe[i]],spe[i]);
    }
    sort(ALL(dists);
    for(int val:spe){
           int dista = dist1[val];
           int findto = dist[1] - dista;

        
    }

    cout<<ans<<endl; 

}
