#include<bits/stdc++.h>
using namespace std;

int main(){
    int y1 = 10;
    int &p = y1;
    p = 20;
    cout<<y1<<endl;
    int y2 = 30;
    p = y2;
    int& p1 = p;
    p1 = 40;
    int y3 = 50;
    p = &y3;
    cout<<y1<<"\n\n";

    /*int* p = &y1;
    *p  = 20;
    cout<<y1<<endl;
    int y2 = 30;
    *p = y2;
    int* p1 = p;
    *p1 = 40;
    cout<<y1<<endl;
    int y3 = 50;
    p = &y3;
    cout<<*p<<endl;*/


}
