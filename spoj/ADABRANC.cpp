#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;


const int MAX = 300005;

struct event {
    int type;
    int id;
    int a;
    int b;
    int wt;
    
    event(){}
    event(int _type,int _id,int _a,int _b,int _wt):
        type(_type),id(_id),a(_a),b(_b),wt(_wt){}

    bool operator < (const event other)const {
        if(wt != other.wt){
            return wt > other.wt;
        }
        return type < other.type;
   }
};

int N,M,Q;
int parent[MAX],componentSize[MAX];
int result[MAX];
vector<event> events;


int findroot(int node){
    return parent[node] == node ? node:parent[node] = findroot(parent[node]);
}
void unionNodes(int x,int y){
    int rootX = findroot(x);
    int rootY = findroot(y);
    if(rootX == rootY){
        return ;
    }
    if(rand() & 1) swap(rootX ,rootY);

    parent[rootY] = rootX;
    componentSize[rootX] += componentSize[rootY];
    componentSize[rootY]=0;
}
int main(){
    scanf("%d%d%d",&N,&M,&Q);
    for(int i=1;i<=N;i++){
        parent[i]=i;
        componentSize[i]=1;
   }

    for(int i=0;i<M;i++){
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        ++a;
        ++b;
        events.push_back(event(0,-1,a,b,l));
   }
    for(int i=0;i<Q;i++){
        int a,x;
        scanf("%d%d",&a,&x);
        ++a;
        events.push_back(event(1,i,a,-1,x));
    }
    sort(events.begin(),events.end());

    for(auto i:events){
        if(i.type == 0){
            unionNodes(i.a,i.b);
       }
        else{
            result[i.id] = componentSize[findroot(i.a)];
       }
   }
    for(int i=0;i<Q;i++){
        printf("%d\n",result[i]);
   }

    return 0;
}

