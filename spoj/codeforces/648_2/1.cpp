#include<bits/stdc++.h>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int pp = max(n,m);
        int row[pp] = {0};
        int col[pp] = {0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x;cin>>x;
                if(x == 1){
                    row[j] = 1;
                    col[i] = 1;
                }
            }
        }
//         print(row,pp);
        int ans = 0;
        for(int i=0;i<pp;i++)if(row[i] == 0 and col[i] == 0)ans++;
        cout<<ans<<endl;
        if(ans %2 ==0  ){
            cout<<"Vivek\n";
        }
        else cout<<"Ashish\n";
        

    }
}
