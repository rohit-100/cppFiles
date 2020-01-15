#include<iostream>
using namespace std;


class Vector{
    private:
        double *elem;
        int sz;
    public:
        Vector(int s): elem{new double[s]},sz{s}
        {
            for(int i=0;i != s;++i)
                elem[i]=0;
        }
        ~Vector(){
            delete[] elem;
        }
        double& operator[](int i){
            if(i>=sz) throw out_of_range{"vector::operator[]"};
            return elem[i];

        }
        int size() const{
            return sz;
        }
        void push_back(double val);

};

int main(){
    Vector v(10);
    try{
        v[v.size()] = 7;
    }
    catch (out_of_range){
        cout<<"out of range operation";
    }

}
