



#include<iostream>
#include<string.h>
using namespace std;
int strcmp(const char* s1,const char* s2){
    while(*s1 and *s2){
        if(*s1 < *s2)return -1;
        else if(*s1 > *s2) return 1;
        else{
            ++s1;
            ++s2;
        }
    }
    if(*s1 ==0 and *s2==0)return 0;
    if(*s1 == 0)return -1;
    return 1;
}


void print(const char* str){
    while(*str){
        cout<<*str;
        ++str;
    }
}

int main(){
    
    char name[]={'r','o','h'};
    name[3]= 'a';
    print(name);
    cout<<strlen(name)<<endl;

    cout<<(int)name[3]<<endl;

    cout << strcmp(name,"rohan");


}
