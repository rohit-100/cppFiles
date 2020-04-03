/*
 * if we do not declare the A::fun() virtual then , b->fun() will print "A" 
 * but if we decleare it virtual the it will print the overrided methode
 *
 */





#include<bits/stdc++.h>
using namespace std;

class A {
    public:
   virtual   void fun(){
        cout<<"A\n";
    }
   void ff(){
       cout<<"ff\n";
   }
};

class B : public A{
    public: 
    void  fun(){
        cout<<"B\n";
    }
};
class C : public B{
    public:
        void fun(){
            cout<<"c\n";
        }
};
int main(){
    A* a = new A();
    A* b = new B();
    A* c = new C();
    C* cc = new C();
    a->fun();
    b->fun();
    c->fun();
    cc->ff();
}
