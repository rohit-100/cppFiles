
/*
   no accepted 
   I used greedy approach for solving the problem
*/




#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int main(){
    while(1){
        int n,m;
        cin>>n;
        if(n == 0)return 0;
        vector<int>a,b;
        for(int i=0;i<n;i++){int x;cin>>x;a.push_back(x);}
        cin>>m;for(int i=0;i<m;i++){int x;cin>>x;b.push_back(x);}
        a.push_back(N);
        b.push_back(N);
        int i=0,j=0;
        long sum1 = 0 ,sum2 = 0;
        long long ans = 0;
        char last = 'p';
        while(i<=n or j<=m){
            if(a[i] < b[j]){
                sum1+=a[i];
                i++;
                last = 'i';
            }
            else if (b[j] < a[i]){
                sum2+=b[j];
                j++;
                last = 'j';
            }
            else{
                if(last == 'p'){
                    ans += a[i];
                }
                else if(last == 'j'){
                    sum2 += b[j];
                    ans += max(sum1,sum2);
                }
                else if (last == 'i'){
                    sum1 += a[i];
                    ans += max(sum1,sum2);
                }

                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
                last = 'p';
            }
        }
        cout<<ans-N<<endl;

    }
}
