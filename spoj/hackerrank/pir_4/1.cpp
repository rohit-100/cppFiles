#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,k;cin>>n>>k;
    set<int> st;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(i<k-1){
            st.insert(x);
            
        }
        else{
            st.insert(x);
            cout<<*st.begin()<<" ";
            st.erase(st.begin());
        }

    }
}
