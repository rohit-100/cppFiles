#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin>>n){
        string pattern,text;
        cin>>pattern>>text;
        text = pattern+"$"+text;
        int m = text.length();
        vector<int>kmp(m,0);
        for(int i=1;i<m;i++){
            int j=kmp[i-1];
            while(j>0 and text[i]!=text[j]){
                j=kmp[j-1];
            }
            if(text[j] == text[i])kmp[i]=j+1;
            else kmp[i]=0;
        }
        //for(int val:kmp)cout<<val<<" ";
        for(int i=0;i<m;i++){
            if(kmp[i]==pattern.length())cout<<i-2*pattern.length()<<endl;
        }
        cout<<endl;

    }
}
