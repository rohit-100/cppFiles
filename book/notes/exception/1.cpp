// catching base and derived class exception
// f both base and derived classes are caught as exceptions then catch block of derived class must appear before the base class.
//

#include<bits/stdc++.h>
using namespace std;
#define FIRST 0
class base{};
class derived:public base{};

int main(){
#ifdef FIRST
    derived d;
    try{
        throw d;
    }
    catch(derived d){
        cout<<"caught drived exception\n";
    }
    catch(base b){
        cout<<"caught base class exception\n";
    }
#endif


#ifndef FIRST
    derived d;
    try{
        throw d;
    }
    catch(base b){
        cout<<"caught base exception\n";
    }
    catch(derived d){
        cout<<"caught derived class exception\n";
    }
#endif

     
}
