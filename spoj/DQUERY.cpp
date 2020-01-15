#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
#define s second
#define f first
vector<int>bit(N,0),fre(N,0);
void update(int x,int val){
    //bit[x] = 1;
    while(x <= N){
        bit[x]+=val;
        x += x &(-x);
    }
}
int get(int x){
    int ans = 0;
    while(x > 0){
        ans += bit[x];
        x -= x&(-x);
    }
    return ans;
}
    
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    arr.push_back(-1);
    for(int i=0;i<n;i++){int x;cin>>x;arr.push_back(x);}
    vector<pair< pair<int,int>,int >> queries;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        queries.push_back({{x,y},i});
    }
    sort(queries.begin(),queries.end());
    vector<pair<int,int> > ans;
    int left = -1,right = -1;
    for(auto val:queries){
        int x = val.f.f;
        int y = val.f.s;
        int ind = val.s;
        if(left == -1 and right == -1){
            for(int j=x;j<=y;j++){
                if(!fre[arr[j]]) update(arr[j],1);
                ++fre[arr[j]];
            }
            left = x;
            right = y;
            int dq = get(y)-get(x-1);
            ans.push_back({ind,dq});
            //cout<<"ans = "<<dq<<" ";
        }
        else{
            while(left < x){
                if(fre[arr[left]]==1){
                    update(arr[left],-1);
                }
                --fre[arr[left]];
                ++left;
            }
            
            while(right < y){
                ++right;
                if(!fre[arr[right]])update(arr[right],1);
                ++fre[arr[right]];
            }
            int dq = get(y)-get(x-1);
            ans.push_back({ind,dq});
            //cout<<"ans = "<<dq<<" ";
        }
        //cout<<x<<" "<<y<<" "<<left<<" "<<right<<endl;
        for(int i=0;i<10;i++)cout<<bit[i]<<" ";
        cout<<endl;
        
    }
    sort(ans.begin(),ans.end());
    for(auto val:ans){
        cout<<val.s<<endl;
    }


}

