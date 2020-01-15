/*
   write a function char* findx(const char* s,const char* x) that finds the first occurance of C-style stirng x in s

*/


#include<iostream>

using namespace std;

bool findx(const char* s,const char* x){
    while(*s){
        const char* temp = s;
        const char* xtemp = x;
        while(*temp and *xtemp and *temp == *xtemp){
            temp++;
            xtemp++;
        }
        if(*xtemp == 0)return true;
        ++s;
    }
    return false;
}


int main(){
    cout<<findx("rohit","ho");
}
