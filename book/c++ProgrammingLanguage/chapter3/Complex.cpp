#include<iostream>
using namespace std;


class Complex{
    double re,im;

    public:
        Complex(double r,double i): re{r},im{i} {}
        Complex(double r):re{r},im{0} {}
        Complex(): re{0},im{0} {}


        double real() const {return re;}
        void real(double d){ re = d;}
        double imag() const { return im;}
        void imag(double d) { im = d;}

        Complex& operator+=(Complex z){
            re += z.re;
            im += z.im;
            return *this;
        }
        Complex& operator-=(Complex z){
            re -= z.re;
            im -= z.im;
            return *this;
        }

        Complex& operator*= (Complex z);
        Complex& operator/= (Complex z);
};



int main(){
    Complex c1(2,3);
    Complex c2(3,4);
    c1+=c2;
    cout<<c1.real()<<endl;
    cout<<c1.imag();<<endl;
}
