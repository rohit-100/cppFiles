#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;
vector<int>primes;
void seive(){
    const int N = 100005;
    int arr[N]={0};
    arr[2]=0;
    for(int i=2;i<N;i++){
        if(arr[i] == 0){
            primes.push_back(i);
            for(ll j = 1ll*i*i; j < N; j += i){
                arr[j]=1;
            }
       }
   }
}

bool next_permutation( vector<int> &arr){
    const int n = arr.size();
    if(n == 1)return false;

    int ind = n-1;
    int i;
    for(i=n-1; i-1 >= 0 ;i--){
        if(arr[i-1] >= arr[i])continue;
        else{
          //  ind = i-1;
            break;
        }
     }
    if(i <= 0)return false;
    ind = i;
    int j;
    for( j = n-1;j >= i;j--){
        if(arr[ind -1] >= arr[j] )continue;
        else break;
    }
    swap(arr[ind -1],arr[j]);
    i=n-1;
    while( ind < i){
        swap(arr[ind] ,arr[i]);
        ind ++;
        i--;
    }
    return true;
}
/*
vector<int> getpfactors(vector<int> &arr){
    long no = 0;
    for(int val:arr) no = no*10 + val;
    vector<int>pfs;
*/


int main(){
       // seive();
        int n;
        cin>>n;
        vector<int>arr;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        sort(arr.begin(),arr.end());
        ll counter = 1;
        
        for(int val:arr)cout<<val<<"";
        cout<<endl;
        while(next_permutation(arr)){
            for(int val:arr)cout<<val<<"";
            cout<<endl;
            counter++;
        }
        cout<<"total = "<<counter<<endl;

        //vector<int> pfactors = getpfactors(arr);
        
        
}
