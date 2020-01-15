#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = (int) 1e9 +7;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;
        vector<int>p,q;
        cin>>n;
        p.resize(n);
        for(int i=0;i<n;i++)cin>>p[i];
        cin>>m;
        q.resize(m);
        for(int j=0;j<m;j++)cin>>q[j];
        sort(p.begin(),p.end());
        sort(q.begin(),q.end());
        
        int ans=INT_MAX;
        for(int i=0;i<p.size();i++){
            int val = p[i];
            int low  =0;
            int high = q.size()-1;
            int best ;
            if(val > q[0] and val < q.back()){
                while(low <= high){
                    int m1 = low + (high - low)/3;
                    int m2 = high - (high - low)/3;
                    if(abs(q[m1] - val) < abs(q[m2] - val)){
                        best = m1;
                        high = m2-1;
                    }
                    else{
                        best = m2;
                        low = m1 + 1;
                    }


                }   
            }
            else if(val<q[0])best = 0;
            else best = q.size()-1;
         ans = min(ans,abs(val - q[best]));
        
        }
        cout<<ans<<endl;
    }
}
