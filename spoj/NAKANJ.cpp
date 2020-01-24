#include<bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
    point(int x,int y){
        this->x = x;
        this->y = y;
    }
    point(){
        x = 0;
        y = 0;
    }
    
};
map<char,int> mp;
void init(){
    for(int i=0;i<8;i++){
        mp[char('a'+i)] = i+1;
    }

}
point getCordinate(string a){
    point p;
    p.x = mp[a[0]];
    p.y = a[1]-'0';
    return p;
}
void print(point p){
    cout<<"x = "<<p.x<<" y = "<<p.y<<endl;
}
struct node{
    point p;
    int level;
    node(point p,int level){
        this->p = p;
        this->level = level;
    }
};
vector<int>dx = {-2,-1,1,2};
bool isValid(int a,int b){
    if(a>=1 and a<=8 and b>=1 and b<=8)return true;
    return false;
}
int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        point src = getCordinate(a);
        point dest = getCordinate(b);
        //print(src);
        //print(dest);
        //cout<<endl;

        node srcNode = node(src,0);
        vector<vector<int> > ans (9,vector<int>(9,-1));
        queue<node> q;
        q.push(srcNode);
        while(!q.empty()){
            node temp = q.front();
            q.pop();
            ans[temp.p.x][temp.p.y]=temp.level;
            int x = temp.p.x;
            int y = temp.p.y;
            for(int val1:dx){
                for(int val2 :dx)if(abs(val1) != abs(val2) and isValid(x+val1,y+val2) and ans[x+val1][y+val2] == -1){
                    q.push(node(point(x+val1,y+val2),temp.level+1));
                }
            }
        }
        cout<<ans[dest.x][dest.y]<<endl;

    }
}
