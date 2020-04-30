#include<bits/stdc++.h>
using namespace std;

long long fun(long long n){
    long long ans = 0;
    while(n){
        int temp = n%10;
        ans += temp*temp;
        n/=10;
    }
    return ans;
}
int main(){

    long long   n;cin>>n;

    unordered_set<long long> st;
    int counter = 1;
    while(true){
        long long temp = fun(n);
//         cout<<temp<<endl;
        if(temp == 1)break;
        if(st.find(temp) != st.end()){
            cout<<"-1\n";
            return 0;
        }
        st.insert(temp);
        n = temp;
        counter++;
    }
    cout<<counter<<endl;

}
