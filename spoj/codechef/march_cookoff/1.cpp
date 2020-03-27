#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string str;cin>>str;
        int x=0,y=0;
        char prev = '$';
        for(char ch:str){
            if(ch == 'L' and prev != 'x'){
                --x;
                prev = 'x';
            }
            else if(ch == 'R' and prev != 'x'){
                ++x;
                prev = 'x';
            }
            else if(ch == 'U' and prev != 'y'){
                ++y;
                prev = 'y';
            }
            else if (ch == 'D' and prev != 'y') {
                --y;
                prev = 'y';
            }
        }
        cout<<x<<" "<<y<<endl;
        
    }
}
