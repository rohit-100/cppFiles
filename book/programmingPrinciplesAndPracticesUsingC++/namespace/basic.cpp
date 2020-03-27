#include<bits/stdc++.h>
using namespace std;


namespace my{
    int val = 100;
    int myfunc(int val);
}

int my::myfunc(int val){
    return 10*val;
}

namespace a{
    namespace b{
        int val  = 20;
    }
}

namespace myclasses{
    class corona;
}
class myclasses::corona{
    public :
        int a,b;
        corona(int val){
            a = b = val;
        }
        void print_message(){
            cout<<"i am corona with "<<a<<" "<<b<<endl;
        }
};

int main(){
    cout<<my::val<<endl;
    cout<<my::myfunc(10)<<endl;
    cout<<a::b::val<<endl;
    myclasses::corona corona_obj(10);
    corona_obj.print_message();
     
}
