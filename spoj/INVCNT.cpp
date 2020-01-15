/*

     I have solved this problem using tho methodes 
      1. merge sort technique
      2. using making a tree using the bits of numbers

      both are giving correct answer but spoj giving TLE in second answer


*/

#include<bits/stdc++.h>
using namespace std;
void compress(vector<int>& arr){
    int n = arr.size();
    //vector<int>index(1e7+5,-1);
   // for(int i=0;i<n;i++)index[arr[i]] = i;
    vector<int>temp;
    for(int val:arr)temp.push_back(val);
    sort(temp.begin(),temp.end());
    temp.erase( unique(temp.begin(),temp.end()),temp.end());
    for(int& val:arr){
        int ind = lower_bound(temp.begin(),temp.end(),val)-temp.begin();
        val = ind+1;
    }

}
template <typename T>
void print(vector<T>& arr){
    for(T val:arr)cout<<val<<" ";
    cout<<endl;
}
        

long  merge(vector<int>& arr,int low ,int high){
    int mid = (low + high)>>1;
    vector<int>temp1(arr.begin()+low,arr.begin()+mid+1);
    vector<int>temp2(arr.begin()+mid+1,arr.begin()+high+1);
    const int mx = INT_MAX;
    temp1.push_back(mx);
    temp2.push_back(mx);
    int i=0,j=0;
    int n = temp1.size(),m = temp2.size();
    int k = low ;
    long  count = 0;
    while(i<n and j < m and !(temp1[i] == mx and temp2[j] == mx)){
        if(temp1[i] <= temp2[j]){
            arr[k++] = temp1[i++];
        }
        else{
            count +=(n-i-1);
            arr[k++] = temp2[j++];
        }
    }
    return count;
}
long  inversion_count(vector<int>& arr,int low,int high){
    if(low >= high)return 0l;
    int mid = (low + high)>>1;
    return inversion_count(arr,low,mid) + inversion_count(arr,mid+1,high)+merge(arr,low,high);
}

struct node{
    long count;
    node* left,*right;
    node(){
        count=1;
        left = right = nullptr;
    }
};

vector<int> get_bit_represtation(int val){
    vector<int>bits;
    while(val){
        if(val%2)bits.push_back(1);
        else bits.push_back(0);
        val/=2;
    }
    while(bits.size()<31)bits.push_back(0);
    reverse(bits.begin(),bits.end());
    return bits;
}
long  total = 0;
void insert(node* start,vector<int>& bits,int ind){
    if(ind >= bits.size())return ;
    /*if(start == nullptr){
        start = new node();
        if(bits[ind] == 1)start->right =  insert(start->right,bits,ind+1);
        else start->left = insert(start->left,bits,ind+1);
        return start;

    }*/
    
   /* if(bits[ind] == 1)start->right =  insert(start->right,bits,ind+1);
    else start->left = insert(start->left,bits,ind+1);
    start->count++;
    return start;
    */
    if(bits[ind] == 1){
        if(start->right == nullptr)start->right = new node();
        else start->right->count++;
        insert(start->right , bits,ind+1);
    }
    else{
        if(start->left == nullptr) start->left = new node();
        else start->left->count++;
        insert(start->left,bits,ind+1);
        if(start->right != nullptr)total+= start->right->count;
    }

}
int depth(node* start){
    if(start == nullptr)return 0;
    return 1+max(depth(start->left),depth(start->right));

}
void print_node(node* start,int depth=2){
    if(start == nullptr)return ;
    cout<<start->count<<endl;
    //cout<<"left\n";
    print_node(start->left,depth+1);
    //cout<<"right\n";
    print_node(start->right,depth+1);
}
long inversion_count_using_segment_tree(vector<int>& arr){
    long ans = 0;
    node* start = new node();
    start->count = 0;
    
    for(int val:arr){
        vector<int>bits = get_bit_represtation(val);
        start->count++;
        insert(start,bits,0);
       // print(bits);
    }
    //cout<<start->left->count<<endl;
    //print_node(start,0);
    //cout<<depth(start)<<endl;
    //cout<<"\n\n";

}

    
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr;
        for(int i=0;i<n;i++){int x;cin>>x;arr.push_back(x);}
        //print(arr);
        vector<int>temp = arr;
         cout<<inversion_count(arr,0,n-1)<<endl;
       // print(arr);
         
        compress(temp);
        inversion_count_using_segment_tree(temp);
        cout<<total<<endl;
        total = 0;

    }

}
