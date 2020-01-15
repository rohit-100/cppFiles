#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,r;
        cin>>a>>b>>c>>r;
        pair<int,int> p,q;
        p.first = min(a,b);
        p.second = max(a,b);
        q.first = c-r;
        q.second = c+r;
        if(p.first <= q.first and p.second >= q.second){
            cout<<p.second-p.first - q.second + q.first<<endl;
        }
            else if(q.first < p.second){
            cout<<q.first - p.first<<endl;
        }
        else if(p.first < q.second){
            cout<<p.second - q.second<<endl;
        }
        else {
            cout<<0<<endl;
        }
    }   
}

