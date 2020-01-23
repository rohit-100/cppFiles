#include<bits/stdc++.h>
using namespace std;

void mul(vector<int>& arr,int val){
    int i=arr.size()-1;
    int inhand = 0;
    while(i>=0){
        int temp = arr[i];
        arr[i] = (arr[i]*val+inhand)%10;
        inhand = (temp*val+inhand)/10;
        i--;
    }

}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr(201,0);
        arr[200]=1;
        for(int i=2;i<=n;i++){
            mul(arr,i);
        }
        int ind = -1;
        for(int val:arr){
            if(val)break;
            ind++;
        }
        arr.erase(arr.begin(),arr.begin()+ind+1);
        for(int val:arr)cout<<val;
        cout<<endl;
    }
}
