#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string str;cin>>str;
        vector<int>mini(n,0),maxi(n,0);
        int m = str.length();
        int filled = 1;
        for(int i=0;i<m;i++){
            if(str[i] == '<'){
                maxi[i] = filled++;
            }
        }
        for(int )
    }
}
