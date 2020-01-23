#include<bits/stdc++.h>
using namespace std;

struct node{
    node* left,*right;
    int val,count;
    node(int val){
        left = right = nullptr;
        this->val = val;
        count=1;
    }
};

node* insert(node* start,int val){
    if(start == nullptr)return new node(val);
    if(val == start->val)return start;
    if(val < start->val)start->left = insert(start->left,val);
    else start->right = insert(start->right,val);
    start->count++;  
    return start;
}
void print(node* start){
    if(start == nullptr)return;
    cout<<start->val<<" "<<start->count<<endl;
    print(start->left);
    print(start->right);
}



int main(){
    node* start = nullptr;
    start = insert(start,1);
    start = insert(start,3);
    start = insert(start,5);
    start = insert(start,8);
    start = insert(start,2);
    print(start);
     
}
