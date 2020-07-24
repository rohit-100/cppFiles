#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int left = 0;
        int right = 0;
        for(char ch:s){
            if(ch == '1')break;
            left++;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0')break;
            right++;
        }
        if(left + right == n){
            cout<<s<<endl;
        }
        else{
            cout<<s.substr(0,left);
            cout<<"0";
            for(int i= n-right;i<n;i++){
                cout<<s[i];
            }
            cout<<endl;
        }
    }
}
