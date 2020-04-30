#include<bits/stdc++.h>
using namespace std;

int main(){

    string s1,s2;
    while((cin>>s1)){
        cin>>s2;
        int n=s1.length();
        int m = s2.length();
        int dp[105][105];
        memset(dp,0,sizeof(dp));
        vector<char>lcs;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
//                     lcs.push_back(s1[i-1]);
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//                 cout<<dp[i][j]<<" ";
            }
//             cout<<endl;
        }
        int i = n;
        int j=m;
        while(i !=0 and j!=0){
            if(dp[i][j] == 1+dp[i-1][j-1] and s1[i-1] == s2[j-1]){
                lcs.push_back(s1[i-1]);
                i--;
                j--;
            }
            else if(dp[i][j] == dp[i-1][j]){
                i--;
            }
            else j--;
        }
        reverse(lcs.begin(),lcs.end());
//         for(char val:lcs)cout<<val<<" ";
//         cout<<endl;
        i=0;j=0;int k = 0;
        while(i<n and j<m and k<lcs.size()){
//             cout<<i<<" "<<j<<" "<<k<<endl;            
            if(s1[i] == s2[j] and s2[j] == lcs[k]){
                cout<<s1[i];
                i++;
                j++;
                k++;
            }
            else if(s1[i] == lcs[k]){
                cout<<s2[j];
                j++;
            }
            else if(s2[j] == lcs[k]){
                cout<<s1[i];
                i++;
            }
            else{
                cout<<s1[i++];
                cout<<s2[j++];
            }
        }
        while(i<n)cout<<s1[i++];
        while(j<m)cout<<s2[j++];
        cout<<endl;
        
    }
}
