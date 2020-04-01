#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        string n,m;
        cin>>n>>m;
        int sum = -1;
        for(int i=0;i<n.length();i++){
            for(int j=0;j<m.length();j++){
               sum = max(sum,atoi(n.c_str())+atoi(m.c_str()));
               swap(m[j],n[i]);
               sum = max(sum,atoi(n.c_str()) + atoi(m.c_str()));
               swap(m[j],n[i]);
            }
        }
        cout<<sum<<endl;
    }
}
