#include<bits/stdc++.h>
using namespace std;

int main(){

    int primes[] = {2,3,5,7,11,13,17,19,23,29,31};
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<pair<int,int> > arr;
//         for(int i=0;i<n;i++){
//             int x;cin>>x;
//             arr.push_back({x,i});
//         }
        set<int>ans;
        vector<int>anss;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            for(int i=0;i<11;i++){
                if(x%primes[i] == 0){
                    ans.insert(i+1);
                    anss.push_back(i+1);
                    break;
                }
            }
        }
        
        for(int val:anss)cout<<val<<" ";
        cout<<endl;
    }
}
