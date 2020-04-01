#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        string str;cin>>str;
        int k,x;cin>>k>>x;
        vector<int>arr(26,0);
        int ans = 0;
        for(char ch : str){
            ++arr[ch-'a'];
            if(arr[ch-'a'] >x and k == 0){
                break;
            }
            if(arr[ch -'a'] > x){
                --k;

            }
            else{
               ++ans;
            }
        }
        cout<<ans<<endl;
    }
}
