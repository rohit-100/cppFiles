#include<bits/stdc++.h>
using namespace std;
class ABC{
    public:
        friend void dost();
    private:
        void print(){
            cout<<"hello workd\n";
        }
};
void dost(){
    ABC abc;
    abc.print();
}
int main(){

    dost();
     
}
