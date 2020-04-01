#include<iostream>
#include<vector>
using namespace std;


template<typename Elem> struct  Node{
    Node* prev;
    Node* succ;
    Elem val;
};
// template<typename Elem> struct list{
//     Link<Elem>* first;
//     Link<Elem>* end;
// };

template<typename Elem> class List{
    private:
        Node<Elem>* first,last;

    public:
        List(){
            first = last = nullptr;
        }
        List(const vector<Elem>& arr){
            for(int i=arr.size()-1;i>=0; i--)insert(begin(),arr[i]);
        }
        class iterator;

        iterator begin();
        iterator end();

        iterator insert(iterator p,const Elem& val);
        iterator erase(iterator p);
        
        void push_back(const Elem& val);
        void push_front(const Elem& val);
        
        void pop_back();
        void pop_front();

        Elem& front();
        Elem& back();
};
template<typename Elem>
List<Elem>::iterator List<Elem>::insert(iterator p,const Elem& val){

}
template < typename Elem> class List<Elem>::iterator{
        Node<Elem>* curr;

    public:
        iterator(Node<Elem>* p):curr(p){}

        iterator& operator++(){curr = curr->succ;return *this;}
        iterator& operator--(){curr = curr->prev;return *this;}
        Elem& operator*(){return curr->val;}
        bool operator==(const iterator& other){ return curr = other.curr; }
        bool operator!=(const iterator& other){ return curr != other.curr; }

};
// iterator List::begin(){
//     return 
// }


int main(){

}
