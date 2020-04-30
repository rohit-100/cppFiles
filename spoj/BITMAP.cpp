#include<bits/stdc++.h>
using namespace std;
#define  f first
#define s second 
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>graph;
        for(int i=0;i<n;i++){
            string temp;cin>>temp;graph.push_back(temp);
        }
        deque<pair<int,pair<int,int> >> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(graph[i][j]-'0')q.push_back({0,{i,j}});
            }
        }
        vector<vector<int> > dist(n,vector<int>(m,-1));
        while(!q.empty()){
            auto curr = q.front();
            q.pop_front();
            if(curr.s.f < 0 or curr.s.f >=n or curr.s.s <0 or curr.s.s >= m or dist[curr.s.f][curr.s.s] != -1)continue;
            dist[curr.s.f][curr.s.s] = curr.f;
            int x = curr.s.f;
            int y = curr.s.s;
            for(int i=-1;i<2;i++){
                for(int j=-1;j<2;j++){
                    if(abs(i)^abs(j)){
                        if(x+i >=0 and x+i < n and y+j >= 0 and y+j < m){
                            q.push_back({curr.f+1,{x+i,y+j}});
                        }
                    }
                }
            }


        }
        for(auto vect:dist){
            for(int val : vect)cout<<val<<" ";
            cout<<endl;
        }
    }
}
