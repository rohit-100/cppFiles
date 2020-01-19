#include<bits/stdc++.h>
using namespace std;
int fun(string str){
    int open = 0;
    int close = 0;
    for(char ch:str){
        if(ch == '{')open ++;
        else {
            if(open){
                open--;
            }
            else{
                close++;
            }
        }
    }
    return open/2+open%2 + close/2+close%2;

}
int main(){
    int t=1;
    while(true){
        string s;
        cin>>s;
        if(s[0]=='-')return 0;
        cout<<t<<". ";
        t++;
        /*
        stack<int>stk;
        for(char ch:s){
            if(ch == '{')stk.push(ch);
            else if(!stk.empty() and stk.top() == '{')stk.pop();
            else stk.push(ch);
        }
        cout<<stk.size()/2<<endl;
        */
        cout<<fun(s)<<endl;
    }

}
