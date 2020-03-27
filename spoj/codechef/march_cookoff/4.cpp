#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define inf -1000000000000000
class node{
    public:
       ll ans,total,pre,suff;
    public:
//        node(){}
       node(ll val):ans(val),total(val),pre(val),suff(val){}

};

node merge(const node a,const node b){
       node temp(0) ;
       temp.total = a.total + b.total;
       temp.ans = max(a.ans,max(b.ans,a.suff+b.pre));
       temp.pre = max(a.pre,a.total+b.pre);
       temp.suff = max(b.suff,a.suff+b.total);
       return temp;
   
}

class segmentTree{
    private:
        vector<node> tree;
        int vect_len;
        int tree_len;
    public:
        segmentTree( vector<int>& arr){
            vect_len = arr.size();
            tree_len = 4*vect_len;
            tree.assign(tree_len,node(inf));
            buildTree(1,1,vect_len,arr);
        }
        void buildTree(int s,int ss,int se,vector<int>& arr){
            if(ss > se)return ;

            if(ss == se){
                tree[s] = node(arr[ss-1]);
                return ;
            }
            int mid = (ss + se)>>1;
            buildTree(s<<1,ss,mid,arr);
            buildTree(s<<1|1,mid+1,se,arr);
            tree[s] = merge(tree[s<<1],tree[s<<1|1]);
        }
        ll query(int x,int y){
            ll  ans =0;
            if(x > 1){
                
                ans +=max(_query(1,1,vect_len,1,x-1).suff,0ll);
//                 cout<<"left ans = "<<ans<<endl;
            }
            if(y < vect_len){
                ans += max(_query(1,1,vect_len,y+1,vect_len).pre,0ll);
//                 cout<<"right ans = "<<ans<<endl;
            }
            ans += _query(1,1,vect_len,x,y).total;
//             cout<<"ans = "<<ans<<endl;
            return ans;
        }
        node _query(int s,int ss,int se,int l, int r){
            if(ss > se or l > se or r < ss)return node(0);
            if(l <= ss and  se <= r){
                return tree[s];
            }
            int mid = (ss + se)>>1;
            node a = _query(s<<1,ss,mid,l,r);
            node b = _query(s<<1|1,mid+1,se,l,r);
            if(ss > mid)return b;
            else if(se < mid+1)return a;
            else return merge(a,b);
        }
        void update(int ind,int val){
            _update(1,1,vect_len,ind,val);
        }
        void _update(int s,int ss,int se,int ind,int val){
            if(ss > se)return ;
            if(ss == se){
                tree[s] = node(val);
                return ;
            }
            int mid = (ss + se)>>1;
            if(ind <= mid){
                _update(s<<1,ss,mid,ind,val);
            }
            else{
                _update(s<<1|1,mid+1,se,ind,val);
            }

           tree[s] = merge(tree[s<<1],tree[s<<1|1]) ;
        }





        node getnode(int ind){
            return tree[ind];
        }





       const  node query_node(int l,int r){
           const node temp = _query(1,1,vect_len,l,r);
           return temp;
       }
};
void print(const node a){
    cout<<"ans = "<<a.ans
        <<" total= "<<a.total
        <<" pre= "<<a.pre
        <<" suff= "<<a.suff<<endl;
}


int main(){

        int t;
        cin>>t;
        while(t--){
            int n;cin>>n;
            int q;cin>>q;
            vector<int>arr;{for(int i=0;i<n;i++){int x;cin>>x;arr.push_back(x);}}
            segmentTree* solver = new segmentTree(arr);           
//             print(solver->getnode(1));
//             print(solver->query_node(1,2));
        while(q--){
            char type;cin>>type;
            if(type == 'Q'){
                int x,y;
                cin>>x>>y;
                cout<<solver->query(x,y)<<endl;
            }
            else{
                int ind,val;cin>>ind>>val;
                solver->update(ind,val);
            }
//             cout<<"yes\n";
        }
    }
}
