#include<iostream>
using namespace std;

class vector{
    private:
        int sz;
        double* elem;
        void copy(const vector& arg){
            for(int i=0;i<arg.sz;++i)elem[i] = arg.elem[i];
        }
        void copy2(const vector& arg,double* p){
            for(int i=0;i<arg.sz;++i)p[i] = arg.elem[i];
        }
    public:
        explicit vector(int n):sz(n),elem(new double[n]){}
        int size()const{return sz;}
        double get(int ind){return elem[ind];}
        void set(int ind,double val){elem[ind]=val;}
        double& operator[](int n){return elem[n];}
        vector(const vector& arg):sz(arg.sz),elem(new double[arg.sz]){
            copy(arg);
        }
        void print(){
            for(int i=0;i<sz;++i)cout<<elem[i]<<" ";
            cout<<endl;
        }

        vector& operator=(const vector& a){
            double* p  = new double[a.sz];
            copy2(a,p);
            delete[] elem;
            elem = p;
            sz = a.sz;
            return *this;
        }
};

void constuctors(){
    vector v(10);
    v.set(5,50);
    v.print();
    vector v2(v);
    v2.set(5,20);
    vector v3 = v2;
    v3.set(5,80.0);
    v2.print();
    v3.print();
}


int main(){
   
    vector v(2);
    v.set(1,5);
    v.print();
    vector v1(4);
    v1.set(2,6.2);
    v1.print();
    v = v1;
    v1.print();
    v1 = v1;
    v1.print();
    char chars[] = {'a','b','c'};
    char name[] = "rohit";
    cout<<sizeof(name)<<endl;
    cout<<sizeof(chars)<<endl;

}
