#include<bits/stdc++.h>
using namespace std;

struct node{
    node* arr[10];
    bool end ;
    node(bool last){
        for(int i=0;i<10;i++)arr[i]=nullptr;
        end =last;
    }
};

bool comp(const string a,const string b){
    return a.length()>b.length();
}

bool insert(node* start ,const string& s,int ind,bool ans){
    if(ind >= s.length()){
        start->end = true;
        return ans;
    }
    if(start->arr[s[ind]-'0'] == nullptr){
        ans = false;
        //cout<<"hf"<<s[ind]<<endl;
        start->arr[s[ind]-'0'] = new node(false);
    }
    return insert(start->arr[s[ind]-'0'],s,ind+1,ans);
    
}
void print(node* start){
    if(start->end == true)return;
    for(int i=0;i<10;i++){
        if(start->arr[i] != nullptr){
            cout<<i<<endl;
            print(start->arr[i]);
        }
    }
}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string>g(n);
        for(int i=0;i<n;i++)cin>>g[i];
        sort(g.begin(),g.end(),comp);
        //for(string s:g)cout<<s<<endl;
        node* start = new node(false);
        bool ans=false;
        for(string s:g){
            ans |= insert(start,s,0,true);
        }
        //print(start);
        if(!ans)cout<<"YES\n";
        else cout<<"NO\n";

    }
}
