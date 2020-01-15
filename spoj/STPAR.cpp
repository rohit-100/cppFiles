#include<bits/stdc++.h>
using namespace std;
int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0)return 0;
        vector<int>arr;
        for(int i=0;i<n;i++){int x;cin>>x;arr.push_back(x);}
        stack<int>stk;
        int need = 1;
        for(int i=0;i<n;){
            if(arr[i] == need){
                need++;
                ++i;
                continue;
            }
            bool hua = false;
            while(!stk.empty() and stk.top() == need){
                need++;
                stk.pop();
                hua = true;
            }
            if(!hua){
                stk.push(arr[i]);
                ++i;
            }
        }
        while(!stk.empty() and stk.top() == need){
            need++;
            stk.pop();
            
        }
        if(stk.empty())cout<<"yes\n";
        else cout<<"no\n";
    }
    }
