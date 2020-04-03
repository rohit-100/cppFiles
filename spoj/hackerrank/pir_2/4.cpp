// giving wa


#include<bits/stdc++.h>
using namespace std;
int pr[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53 };
int inv(int i){
    int ans = 0;
    int ind = 0;
    while(i){
        if(!(i&1)){
            ans += (1<<ind);
        }
        ind++;
        i>>=1;
    }
    return ans;
}
int main(){

    int n;cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
    }
    int N= 16;
    int fre[1<<N];
    for(int i=0;i<(1<<N);i++)fre[i] = 0;
    for(int val:arr){
        int mask = 0;
        for(int i=0;i<16;i++){
            if(val%pr[i] == 0){
                mask += (1<<i);
            }
        }
        if(fre[mask] == 0)
            fre[mask] = 1;
        
    }
    for(int i=0;i<(1<<N);i++){
         
        fre[i] += fre[inv(i)];
    }
    for(int i=0;i<50;i++)cout<<fre[i]<<" ";
    cout<<endl;
    int ans = 0;
    for(int i=0;i<(1<<N);i++){
        if(fre[i] > ans){
            ans = fre[i];
        }
    }

    cout<<ans<<endl;



}
