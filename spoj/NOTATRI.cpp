#include<bits/stdc++.h>
using namespace std;

int main(){
//     int _;cin>>_;
    while(true){
        int n;cin>>n;
        if(n == 0)break;
        vector<int>arr(n+1);
        for(int i=0;i<n;i++)cin>>arr[i+1];
        sort(arr.begin()+1,arr.end());
        long long ans = 0;
        bool flag = false;
        for(int i = 1;i<n-1;i++){
            for(int  j = i+1;j<n;j++){
                int sum = arr[i] + arr[j];
                int low = j+1;
                int high = n;
                int piv = -1;
                while(low <= high){
                    int mid = (low + high)>>1;
                    if(arr[mid] > sum){
                        piv = mid;
                        high = mid-1;
                    }
                    else low = mid +1;
                }
                if(piv == -1){
                    flag = true;
                    break;
                }
//                 cout<<piv<<endl;
                ans += n-piv+1;

            }
//             if(flag)break;
        }
        cout<<ans<<endl;
    }
}

