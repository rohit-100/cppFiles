#include<bits/stdc++.h>
using namespace std;
vector<int>primes;
void pp(){
    const int n = 3000000;
    vector<bool> pr(n,true);
    for(int i=2;i<n;i++){
        if(pr[i]){
            for(int j = 2*i;j<n;j+=i)
                pr[j]=false;
            primes.push_back(i);
        }
    }
}

int main(){
    pp();
    //for(int i=0;i<50;i++)cout<<primes[i]<<" ";
    //cout<<endl;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>m>>n;
        int len = n-m+1;
        vector<bool>arr(len,true);
        for(int val:primes){
            if(val > n)break;
            int rem = m%val;
            int prev = m-rem;
            if(rem){
                prev += val;
            }
            if(prev/val == 1)prev += val;
            for(;prev<=n;prev+=val){
                arr[prev-m] = false;
            }
        }
        int ans=0;
        for(int i=max(0,2-m);i<len;i++)if(arr[i])cout<<i+m<<"\n";
        if(t != 0)cout<<"\n";
    }


}
