#include<bits/stdc++.h>
using namespace std;
bool isprime(const int n){
    for(long i=2;i*i <=n;i++){
        if(n % i == 0)return false;
    }
    return true;
}

int main(){

    int tc;cin>>tc;
    while(tc--){
        int n;cin>>n;
        if((n != 1 and n%2 == 1) or n == 2){
            cout<<"Ashishgup\n";
            continue;
        }
        if(n == 1 or (n&(n-1)) == 0){
            cout<<"FastestFinger\n";
            continue;
        }
        int tows = 0;
        while(n%2 == 0){
            n/=2;
            tows++;
        }
        if(tows == 1 and isprime(n)){
            cout<<"FastestFinger\n";
        }
        else cout<<"Ashishgup\n";
    }
}
