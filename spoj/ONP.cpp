#include<bits/stdc++.h>
using namespace std;


bool isoperator(char ch){
    vector<char> arr = {'+','*','/','^','-'};
    for(char ss:arr){
        if(ss == ch)return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        stack<char>stk;
        for(char ch:str){
            if(ch == '(' or isoperator(ch)){
                stk.push(ch);
            }
            else if(ch>='a' and ch<='z'){
                cout<<ch;
            }
            else{
                while(!stk.empty() and stk.top() != '('){
                    cout<<stk.top();
                    stk.pop();
                }
                stk.pop();
            }
        }
        cout<<endl;
    }
}

