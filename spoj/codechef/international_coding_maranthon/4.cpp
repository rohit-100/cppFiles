#include<bits/stdc++.h>
using namespace std;

double fun(double ss,int b,int c){
    double val = (1.0* (ss*ss +ss*b+c))/sin(ss);

    return val; 
}

int main(){

    int t;
    cin>>t;





    while(t--){
        int c,b;
        cin>>b>>c;

        double high = 1.57;
        double low = 0.0000111;
        int cc = 200;
        double ans = 1000000,ans2 = 1000000;
        while(cc--){
            double mid1 = low + (high-low)/3;
            double mid2 = high - (high-low)/3;
            double f1 = fun(mid1,b,c);
            double f2 = fun(mid2,b,c);

            ans = min(ans,min(f1,f2));
            if(f1 < f2){
                high = mid2;
            }
            else{
                low = mid1;
                ans2 = f2;
            }
        }

        printf("%.10lf\n",ans);
    }
}
