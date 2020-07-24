#include<bits/stdc++.h>
using namespace std;

const int N = 10000007;
int lp[N];
void seive(){
    for(int i=0;i<N;i++)lp[i] = i;
    for(int i=2;i<N;i++){
        if(lp[i] == i){
            for(long long j = i;j<N;j+=i)lp[j] = i;
        }
    }

}

int main(){
    seive();
    int n;cin>>n;
    vector<set<int> > arr(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        while(x != 1){
            arr[i].insert(lp[x]);
            x = x/lp[x];
        }
    }
    vector<pair<int,int> > ans(n);
    for(int i=0;i<n;i++){
        if(arr[i].size() > 1){
            ans[i].first = *arr[i].begin();
            ans[i].second = *(++arr[i].begin());
        }
        else {
            ans[i].first = -1;
            ans[i].second = -1;
        }
    }
    for(int i=0;i<n;i++)cout<<ans[i].first<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)cout<<ans[i].second<<" ";
    cout<<endl;
    
}
