#include<bits/stdc++.h>
using namespace std;
bool ok(double);
vector<int>b,h,w,l;
long long int V;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        b.clear();h.clear();w.clear();l.clear();        
        for(int i=0;i<n;i++){
            int p,q,r,s;
            cin>>p>>q>>r>>s;
            b.push_back(p);
            h.push_back(q);
            w.push_back(r);
            l.push_back(s);
        }
        cin>>V;
        double low = 0.00;
        double high = (double)1e12;
        double ans = -1;
        int round = 200;
        while(round--){
            double mid = (low+high)/2;;
            if(ok(mid)){
                ans = mid;
                high = mid;
            }
            else{
                low = mid;
            }
        }
        if(ans != -1)
        printf("%0.2f\n",ans);
        else printf("OVERFLOW\n");
    }
}
bool ok(double mid){
    double total = 0.0;
    for(int i=0;i<b.size();i++){
        double diff = mid - b[i];
        if(diff <= 0){
            continue;
        }
        else{
            total += 1ll*w[i]*l[i]*min(mid-b[i],(double)h[i]);
        }
    }
    if(total >= (double)V)return true;
    return false;
}

