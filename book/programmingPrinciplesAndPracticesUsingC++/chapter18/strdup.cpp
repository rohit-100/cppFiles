#include<iostream>
using namespace std;

char* strdup(const char* str){
    int len = 0;
    const char* temp = str;
    while(*temp){
        ++len;
        ++temp;
    }
    //cout<<"lenght = "<<len<<endl;
    char* p = (char*)malloc(len*sizeof(char));
    for(int i=0;i<len;i++)p[i] = str[i];
    p[len] = 0;
    /*char* pp = p;
    while(*pp){
        cout<<*pp;
        ++pp;
    }
    cout<<endl;*/
    return p;
}

int main(){
    char name[] = "rohit";
    char* name1 = strdup(name);
    while(*name1){
        cout<<*name1;
        ++name1;
    }
}
