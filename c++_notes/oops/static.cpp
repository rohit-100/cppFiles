/*
 * static variables are only initialized once. for premitive types value is 0, for user data type it is not.
 *
 * static variabes are placed in static storage area.
 *
 * any variable decleared static lasts till the end of the prograame , i.e. it's destructor will be called at the end of the programme.
 *
 * static members inside class  need to be defined explecitly 
 * 
 * static function cannot access ordinary data members or member function  , but only static data members and static member functions.
 *      it does not have any this keyword that's why it can't access ordinary  data members and  member function
 *
 *
 * a static member function can't be virtual , const ,and volatile.   
 * 
 */




#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        int a;
        A(int val){
           a = val; 
           cout<<"A's constuctor is called\n";
        }
        A(){
            cout<<"default of A is called\n";
            a = 10;
        }
};


class B{
    public:
       static   A a; 
        B(){
            cout<<"B's constructor is called\n";
        }
};

A B::a;             // we have to explicitly define the varibale that was decleared static, because it is not initalized by contructor.


int main(){
    
    B b; 

}
