#include<bits/stdc++.h>
using namespace std;
const int N  = 100;
int pr[N+1];
void seive(){
    for(int i=2;i<=N;i++)pr[i] = i;
    for(int i=2;i<=N;i++){
        if(pr[i] == i){
            for(int j=2*i;j<=N;j+=i)pr[j] = i;
        }
    }
}
set<int> facts(int val){
    set<int> prs ;
    while(val > 1){
        prs.insert(pr[val]);
        val = val/pr[val];
    }
    return prs;
}

int main(){
    seive();
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr;
        for(int i=0;i<n;i++){
            int x;cin>>x;arr.push_back(x);
        }
        vector<int> fact[101];
        for(int val:arr){
            set<int> prs = facts(val);
            for(auto ff:prs)fact[ff].push_back(val);
        }
        int maxi = 0;
        int ind = 0;
        for(int i=0;i<= 100;i++){
            if(fact[i].size() > maxi){
                maxi = fact[i].size();
                ind = i;
            }
        }
        cout<<maxi<<endl;
    }
}
