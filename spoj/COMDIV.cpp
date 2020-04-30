#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
int hpf[N];
void init(){
    for(int i=0;i<N;i++)hpf[i] = i;
    for(int i=2;i<N;i++)if(i == hpf[i]){
        for(int j=2*i;j<N;j+=i)hpf[j] = i;
    }
}
map<int,int> get_factors(int val){
    map<int,int> fre;
    while(val != 1){
        fre[hpf[val]]++;
        val /= hpf[val];
    }
    return fre;
}
int get_answer(map<int,int>& a,map<int,int> &b){
    int ans = 1;
    for(auto it:a){
        int key = it.first;
        int val = it.second;
        if(b.find(key) != b.end()){
//             cout<<"yes\n";
            ans *= (1+min(val,b[key]));
        }
    }
    return ans;
}
int main(){
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;scanf("%d%d",&a,&b);
        auto aa = get_factors(a);
        auto bb = get_factors(b);
//         for(auto val:bb)cout<<val.first<<" "<<val.second<<endl;
        printf("%d\n",get_answer(aa,bb));
    }
}
