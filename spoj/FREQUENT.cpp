#include<bits/stdc++.h>
using namespace std;

struct  Node{
    int val,fre;
    Node(){}
    Node(int _val,int _fre):val(_val),fre(_fre){}
};

struct TreeNode{
    Node pref,suff;
    int ans;
    TreeNode(){}
    TreeNode(int val){
        ans = 1;
        pref = Node(val,1);
        suff = Node(val,1);
    }
};

ostream& operator<<(ostream& out,const TreeNode& val){
     out<<"{"<<val.pref.val<<","<<val.pref.fre<<"}"<<val.ans<<"{"<<val.suff.val<<","<<val.suff.fre<<"}";
     return out;
}



class Tree{
    public:
        int n,N;
        vector<TreeNode>segTree;
    Tree(const vector<int>& arr){
        n = arr.size();
        N = 4*n;
        segTree.resize(N);
        build(1,1,n,arr);
    }
    void build(int s,int ss,int se,const vector<int>&arr){
        if(ss > se)return;
        if(ss == se){
            segTree[s] = TreeNode(arr[ss-1]);
            return ;
        }
        int mid = (ss + se)>>1;
        build(s<<1,ss,mid,arr);
        build(s<<1|1,mid+1,se,arr);
        segTree[s] = merge(segTree[s<<1],segTree[s<<1|1]);
    }
    TreeNode merge(TreeNode a,TreeNode b){
        TreeNode ans ;
        ans.ans = max(a.ans,max(b.ans,a.suff.val == b.pref.val?a.suff.fre+b.pref.fre:0));
        ans.pref = a.pref.val != b.pref.val ? a.pref:Node(a.pref.val,a.pref.fre+b.pref.fre);
        ans.suff = b.suff.val != a.suff.val? b.suff:Node(b.suff.val,b.suff.fre+a.suff.fre);
        return ans;
    }
    TreeNode query(int l ,int r){
        return __query(1,1,n,l,r);
    }
    TreeNode __query(int s,int ss,int se,int l,int r){
//         cout<<ss<<" "<<se<<endl;
        if(l<= ss and se<= r)return segTree[s];
        int mid = (ss + se)>>1;
//         TreeNode ans ;
        if(mid >= r)return __query(ss<<1,ss,mid,l,r);
        else if(mid < l) return __query(ss<<1|1,mid+1,se,l,r);
        TreeNode aa = __query(s<<1,ss,mid,l,r);
        TreeNode bb = __query(s<<1|1,mid+1,se,l,r);
        return merge(aa,bb);
    }
};
int main(){
    while(true){
        int n,m;
        cin>>n;if(n==0)break;
        cin>>m;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        Tree t(arr);
        cout<<t.query(2,2)<<" "<<t.query(3,3)<<endl;
        while(m--){
            int x,y;
            cin>>x>>y;
             cout<<t.query(x,y);
             cout<<endl;
        }
    }
     
}
