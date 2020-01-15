#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;

int main(){
    int n;
    int val;
    cin>>n>>val;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());

    int low = 0;
    int high = arr.size() -1;
    int best ;
    while(low <= high){
        int m1 = low + (high - low )/3;
        int m2 = high - (high - low)/3;
        if(abs(arr[m1]-val) < abs(arr[m2] - val)){
            best = m1;
            high = m2-1;
         }
        else{
            best = m2;
            low = m1+1;
        }
    }
    cout<<arr[best]<<endl;
}
