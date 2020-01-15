#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;

const int N = 20005;
bitset<N> bs[N];


int main(){

    int q;
    cin>>q;
   // cout<<q<<endl;
    while(q--){
        char type;
        int x,y;
        cin>>type>>x>>y;
        if(type == '+'){
            bs[x].set(y);
        }
        else if(type == '-'){
            bs[x].reset(y);
        }
        else if(type == 'v'){
            //cout<<bs[x]<<endl;
            cout<<int((bs[x]|bs[y]).count())<<"\n";
       }
        else if(type == '^'){
            cout<<int((bs[x] & bs[y]).count())<<"\n";
        }
        else if(type == '!'){
            cout<<int((bs[x]|bs[y]).count()) -int( (bs[x] & bs[y]).count())<<"\n";
       }
        else {
            cout<<int((bs[x] ^ (bs[y] & bs[x])).count())<<"\n";
        }
      //  cout<<"type == "<<type;
       // cout<<type<<endl;
       // cout<<bs[x][50]<<endl;
}
}
