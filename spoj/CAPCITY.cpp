#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >& g,vector<bool>& done,int src,vector<int>& ssc){
    if(done[src])return ;
    done[src] = true;
    for(int vv:g[src])if(!done[vv])dfs(g,done,vv,ssc);
    ssc.push_back(src);
}
void dfs1(vector<vector<int> >& revg,vector<bool>& done,int mv,vector<int>& ans){
    if(done[mv] == true)return;
    ans.push_back(mv);
    done[mv] = true;
    for(int vv:revg[mv])if(!done[vv])dfs1(revg,done,vv,ans);
}

int main(){

    int n,m;cin>>n>>m;
    vector<vector<int> > graph(n+1);
    for(int j=0;j<m;j++){
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
    }
    vector<bool> done(n+1,false);
    vector<int> ssc;
    for(int i=1;i<=n;i++)if(!done[i]){
        dfs(graph,done,i,ssc);
        
    } 
    vector<vector<int> > revg(n+1);
    for(int i=1;i<=n;i++){
        for(int val:graph[i]){
            revg[val].push_back(i);
            //cout<<val<<" "<<i<<endl;
        }
    }

    vector<int>ans;
    fill(done.begin(),done.end(),false);
    for(;!ssc.empty();){
        int val = ssc.back();
        if(!done[val]){
            vector<int>temp;
            dfs1(revg,done,val,temp);
            if(temp.size() >1){
                for(int ff:temp)ans.push_back(ff);
            }
        }
        ssc.pop_back();
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int val:ans)cout<<val<<" ";
    cout<<endl;

}

