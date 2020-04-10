#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;
    long long  arr[n+1][n+1];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=n;j++){
            long long x;cin>>x;
            x += arr[i][j-1];
            x += arr[i-1][j];
            x -= arr[i-1][j-1];
            arr[i][j] =x;
        }
        
    }
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=n;j++)cout<<arr[i][j]<<" ";
//         cout<<endl;
//     }
    int high = n;
    int low = 1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high)>>1;
        bool flag = false;
        for(int i=1;i+mid-1<=n;i++){
            for(int j=1;j+mid-1<=n;j++){
                if(arr[i+mid-1][j+mid-1]-arr[i-1][j+mid-1]-arr[i+mid-1][j-1]+arr[i-1][j-1]>=k){
                    flag = true;
                    break;
                }

            }
        }
        if(flag){
            ans = mid;
            high = mid-1;

        }
        else{
            low = mid+1;
        }
    }
    cout<<ans<<endl;

    

}
