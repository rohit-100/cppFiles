#include<bits/stdc++.h>
using namespace std;

bool is_anagram(const string &a, const string &b){
    int ones = 0;
    int zeros = 0;
    for(int i=0;i<a.length();i++){
        if(a[i] == '0')zeros++;
        else ones++;
        if(b[i] == '0')zeros--;
        else ones--;
    }
    return ones == 0 and zeros == 0;
}

int main(){

    int n;cin>>n;
    string a,b;
    cin>>a>>b;
    if(!is_anagram(a,b)){
        cout<<-1<<endl;
        return;
    }
    vector<int> p,q;
    for(int i=0;i<n;i++){
        int x = a[i]-'0';
        int y = b[i]-'0';
        if(x^y){
            if(x)p.push_back(i);
            else q.push_back(i);
        }
    }
    int ans = 0;
    const int m = p.size();
    vector<bool> done(m,false);
    while(true){
        bool temp = true;
        
    }

}
