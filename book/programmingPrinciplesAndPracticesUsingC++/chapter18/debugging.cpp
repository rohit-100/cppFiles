#include<iostream>
using namespace std;


class X{
    private:
        int val;
    public:
        void out(const string& s){
            cerr<<this<<"->"<<s<<": "<<val<<"\n";
        }
        X(){
            val = 0;
            out("X()");
        }
        X(int v):val(v){
            out("X(int)");
        }
        X(const X& x):val(x.val){
            out("X(X&)");
        }
        X& operator= (const X& a){
            val = a.val;
            out("X::opeartor=()");
            return *this;
        }
        ~X(){
            out("~X()");
        }
};
int main(){

    X a(10);
    X b = 20;
    X* c = new X(23);
    a = *c;
    X d(a);
    delete c;




}
