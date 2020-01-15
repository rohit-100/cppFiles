#include<bits/stdc++.h>
using namespace std;
vector<int>check;
vector<int>primes;
void init(){
    int n = 10000;
    check.assign(n,1);
    for(int i=2;i<n;i++){
        if(check[i]){
            for(int j=2*i;j<n;j+=i)check[j]=0;
        }
    }
    for(int i=1000;i<n;i++)if(check[i])primes.push_back(i);
}
void getpossibles(vector<int>& pp,int val){

vector<vector<int> >* get(){
    int n = 100000;
    vector<vector<int> >* pp = new vector<vector<int> >(n,vector<int>());
    for(int val:primes){
        vector<int>possibles;
        getpossibles(possibles,val);

    }
    return pp;
}

int main(){
 init();
// for(int val:primes)cout<<val<<" ";
 //cout<<primes.size();
 vector<vector<int> >* g = get();
 for(int i=0;i<19;i++)cout<<(*g)[i].size()<<endl;

}
