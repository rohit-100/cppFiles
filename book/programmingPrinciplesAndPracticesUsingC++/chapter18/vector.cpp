#include<iostream>
using namespace std;

class vector{
    private:
        int sz;
        double* elem;
    public:
        explicit vector(int n):sz(n),elem(new double[n]){}
        int size()const{return sz;}
        double get(int ind){return elem[ind];}
        void set(int ind,double val){elem[ind]=val;}
        double& operator[](int n){return elem[n];}
};

int main(){
    vector v(10);
    int x = v[2];
    v[3] = 5;
    cout<<v[3]<<endl;

}
