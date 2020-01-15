#include<iostream>
using namespace std;

class Vector{
    public:
        Vector(int s):elem{new double[s]},sz{s}{}
        double& operator[] (int i){return elem[i];}
        int size(){return sz;}
    private:
        double *elem;
        int sz;
};


int main(){
    Vector v(5);
    for(int i=0;i<5;i++){
        cin>>v[i];
    }
    double sum = 0.0;
    for(int i=0;i<v.size();i++){
        sum += v[i];
    }
    cout<<"totaling is "<<sum<<endl;
}
