#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;cin>>n;
    vector<int>arr;{for(int i=0;i<n;i++){int x;cin>>x;arr.push_back(x);}}
    
    priority_queue<int>pq;
    for(int val:arr)pq.push(val);
    int prev = pq.top();
    pq.pop();
    while(true){
        if(pq.empty() or pq.top() != prev){
            cout<<prev;
            exit(0);
        }
        else{
            pq.pop();
            prev = pq.top();
            pq.pop();
        }
    }
    return 0;
}
