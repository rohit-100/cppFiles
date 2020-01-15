#include<bits/stdc++.h>
using namespace std;
void fun(vector<int> &arr){
    bool bone=true,bzero=true;
    int one = -1;
    int zero = 1;
    for(int &val : arr){
        if(val == 0 ){
            bzero = false;
            if(!bone) --one;
            bone = true;
            val = zero;
        }
        else{
            bone = false;
            if(!bzero) ++zero;
            bzero = true;
            val = one;
         }
     }
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>row,col;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        row.push_back(x%2);
    }
    for(int i=0;i<n;i++){
        int x;cin>>x;col.push_back(x%2);
    }
    fun(row);
    fun(col);
/*    for(int val:row)cout<<val;
    cout<<endl;
    for(int val:col)cout<<val;*/
    while(q--){
        int ar,ac,br,bc;
        cin>>ar>>ac>>br>>bc;
        if(row[ar-1] == row[br-1] and col[ac-1] == col[bc-1] )
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}
