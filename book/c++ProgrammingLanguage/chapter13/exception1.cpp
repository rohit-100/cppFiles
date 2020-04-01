#include<bits/stdc++.h>
using namespace std;
void g();
void h();
// struct My_error{
//     string message;
//     My_error(const string& mess):message(mess){}
// };
struct My_error2:std::runtime_error{
    const char* what() const noexcept { return " My_error2"; }
};
void f(){
    string name{"rohit"};
    try {
        string s = "in";
        g();
    }
    catch(std::exception& e){
        cout<<e.what()<<endl;

    }
}
void g(){
    string s = "excess";
    {
        string s = "or";
        h();
    }
}
void h(){
    string s = "not";
    throw My_error2{};
    string s2 = "at all";
}
int main(){
    f();
}
