/*
 *
 * A friend class can access private and protected members of other classs in which it is declared as friend.
 *
 * same for friend function
 *     1. a methode of another class
 *     2. a global function
 *
 *
 *
 *  1. friendship is not mutual. if class A is friend of B , then B is not the friend of A.
 *
 *  2. friendship is not inherited
 *
 *  3. The concept of friendship is not in java.
 *
 */


#include<bits/stdc++.h>
using namespace std;

class Node {
    private:
        int key;
        Node* next;

        friend class LinkedList;
    public:
        Node(int val):key(val),next(nullptr){}
};
class LinkedList {
    private:
        Node* head;
    public:
        LinkedList(){
            head = nullptr;
        }
        void insert_front(int val){
            if(head == nullptr){
                head = new Node(val);
            }
            else{
                Node* temp = new Node(val);
                temp->next = head;
                head = temp;
            }
        }
        void display(){
            Node* temp = head;
            while(temp != nullptr){
                cout<<temp->key<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        void delete_front(){
            if(head != nullptr){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
};


int main(){
    LinkedList ll;
    ll.insert_front(50);
    ll.insert_front(40);
    ll.insert_front(30);
    ll.display();
    ll.delete_front();
    ll.display();
     
}
