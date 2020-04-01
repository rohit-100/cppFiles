#include<bits/stdc++.h>
using namespace std;

class base{
    public :
        void print(){
            cout<<"yes base\n";
        }
};


class A : virtual public base{
};


class B : virtual  public base{
};


class C : public A,public B{
    
};
int main(){

    C c;
    c.print();
}
