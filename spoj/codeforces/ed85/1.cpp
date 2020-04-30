#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int a = 0,b=0;
        bool flag = true;
        for(int i=0;i<n;i++){
            int x,y;cin>>x>>y;
//             cout<<x<<" "<<y<<endl;
            int del1 = x-a;
            int del2 = y-b;
            
            if(x >= y and x >= a and y>=b and del1 >=0 and del2>=0 and del1 >= del2){
                a = x;
                b = y;
            }
            else{
                flag = false;
                a =x;
                b = y;
                
            }
        }
        if(!flag){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
}

