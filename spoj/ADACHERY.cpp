#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;

const int MAX = 100050;
bitset<MAX> bs[MAX];
vector<pair<int,int> > edges;
int degree[MAX];
int N,M;


int main(){
        cin>>N>>M;
        for(int i=0;i<M;i++){
            int x,y;
            cin>>x>>y;
            bs[x][y]=1;
            bs[y][x]=1;
            degree[x]++;
            degree[y]++;
            edges.push_back({x,y});
       }
        ll ans =0;
        for(int i=0;i<N;i++){
            ans += ((1ll*degree[i])*(degree[i]-1))/2;
        }
        for(auto edge :edges){
            ans -= (bs[edge.first]&bs[edge.second]).count();
       }
        cout<<ans<<endl;

}
