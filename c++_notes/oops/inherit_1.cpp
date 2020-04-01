#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        int x;
    protected:
        int y;
    private: 
        int z;

};

class B: public A{

};
class C: protected A{

};
class D: private A{

};
class E:public D{

};
int main(){
//     D d;
//     cout<<d.x<<endl;
//     E e;
//     cout<<e.x;
//       A a;
//       cout<<a.x<<endl;
//        C c;cout<<c.x<<endl;
        B b;cout<<b.y<<endl;
}
