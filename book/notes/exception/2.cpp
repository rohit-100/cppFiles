// stack unwinding in exception handling
//


#include<bits/stdc++.h>
using namespace std;
class My_exception{};

class dummy{
    public:
        dummy(string s):my_name{s}{
            cout<<"string constructor   "<<s<<"\n";
        }
        dummy(const dummy& other):my_name(other.my_name){
            cout<<"other constructor\n";
        }
        ~dummy(){  cout<<"in destructor   "<<my_name<<"\n";}
        string my_name;
};
void funB(const dummy& B){
    dummy temp("fd");
    cout<<"in funB\n";
    throw My_exception{};
    cout<<"going out of funB\n";
}
void funA(const dummy& A){
    dummy temp("heelo");
    cout<<"in funA\n";
    funB(A);
    cout<<"going out of funA\n";
}
int main(){
  dummy d("rohit")  ;
  try{
      funA(d);

  }
  catch(My_exception& e){

  }
     
}
