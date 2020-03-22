#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    vector<string>arr;
    set<string>st;
    for(int i=0;i<n;i++){string x;cin>>x;arr.push_back(x);st.insert(x);}
    int len = 0;
    string mid = "";
    map<string,string>mp;
    while(!st.empty()){
        string x = *st.begin();
        string y = x;
        reverse(x.begin(),x.end());
        if(st.find(x) != st.end() and st.find(x) != st.begin()){
            mp[x] = y;
            st.erase(x);
            st.erase(y);
        }
        else if(st.find(x) == st.begin()){
            string temp = y;
            reverse(y.begin(),y.end());
            if(temp == y and y.size() > mid.size()){
                mid = y;

            }
            st.erase(y);
        }
        else{
            st.erase(y);
        }

    }
//     cout<<mid<<endl;
    for(auto it:mp){
//         cout<<it.first<<" "<<it.second<<endl;
        mid = it.first + mid + it.second;
    }

    cout<<mid.size()<<endl;
    cout<<mid<<endl;
}
