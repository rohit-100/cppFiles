// #include<bits/stdc++.h>
// using namespace std;
// 
// int main(){
// 
//     int x,y,a,b,c;cin>>x>>y>>a>>b>>c;
//     priority_queue<int> p,q,r;
//     for(int i=0;i<a;i++){
//         int x;cin>>x;p.push(x);
//     }
//     for(int i=0;i<b;i++){
//         int x;cin>>x;q.push(x);
//     }
//     for(int i=0;i<c;i++){
//         int x;cin>>x;r.push(x);
//     }
//     long long ans = 0;
//     int reds  = 0;
//     while(reds < x){
//         if( !p.empty() and !r.empty()){
//             if(p.top() > r.top()){
//                 ans += p.top();
//                 p.pop();
//             }
//             else{
//                 ans += r.top();
//                 r.pop();
//             }
//         }
//         else if(!r.empty()){
//             ans += r.top();
//             r.pop();
//         }
//         else{
//             ans += p.top();
//             p.pop();
//         }
//         reds++;
//     }
//     int greens = 0;
//     while(greens < y){
//         if( !r.empty() and !q.empty()){
//             if(r.top() > q.top()){
//                 ans += r.top();
//                 r.pop();
//             }
//             else{
//                 ans += q.top();
//                 q.pop();
//             }
//         }
//         else if(!q.empty()){
//             ans += q.top();
//             q.pop();
//         }
//         else{
//             ans += r.top();
//             r.pop();
//         }
//         greens++;
//     }
//     cout<<ans<<endl;
// }
//
//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>
void take_input(vector<T>& arr,T size){
    for(int i=0;i<size;i++){
        T x;cin>>x;arr.push_back(x);
    }
}
int main(){

    int x,y,a,b,c;cin>>x>>y>>a>>b>>c;
    vector<int>p,q,r;
    take_input(p,a);
    take_input(q,b);
    take_input(r,c);
    sort(p.rbegin(),p.rend());
    sort(q.rbegin(),q.rend());
    sort(r.rbegin(),r.rend());
    int red = 0,green = 0;
    int i=0,j=0,k=0;
    long long ans = 0;
    while(i+j+k < x+y){
        int maxi = max(p[i],max(q[j],r[k]));
        ans += maxi;
        if(maxi == p[i]){
            ++i;

        }
        else if(maxi == q[j]) ++j;
        else ++k;
    }
    cout<<ans<<endl;;

}
