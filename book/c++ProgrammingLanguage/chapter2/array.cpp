#include<iostream>
using namespace std;

void fun1(){
    
    char v[6]{'a','b','c','d','e','f'};
    char *p = &v[3];
    cout<<*p;

}

void fun2(){
    int v[] = {0,1,2,3,4,5,6};

    for(auto x:v)
        cout<<x<<" ";
    for(auto x : {10,21,50,32})
        cout<<x<<'\n';

}
void increment(){
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    for(auto& x : v)
        ++x;
    for(auto x : v)
        cout<<x<<" ";
}
void nulltest(){
    double *pd = nullptr;
}
int count_x(char *p,char x){
    if(p == nullptr ) return 0;
    int count = 0;
    for(; *p != 0 ; ++p ){
        if( *p == x)
            ++count;
    }
    return count;
}
void countTest(){
    char arr[] {'a','b','a','c','d','a'};
    cout<<count_x( arr ,'a');
}

int main(){
    //fun2();
    //increment();
    //nulltest();
    countTest();
}

