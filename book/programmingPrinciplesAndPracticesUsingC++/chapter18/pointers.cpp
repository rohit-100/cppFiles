#include<iostream>
#include<vector>
using namespace std;
void pointer_arithmetic(){
    
    double d[50];
    double* p1 = &d[0];
    double* p2 = p1+7;
    double* p3 = &d[7];
    cout<<p2<<endl;
    cout<<p3<<endl;
    if(p2 != p3)cout<<"impossible";
}

void sizeof_array(){
    char ch[100];
    vector<int>arr(144555);
    cout<<sizeof(ch)<<endl;
    cout<<"size of vector "<<sizeof(arr)<<endl;
}

int strlen(const char* p){
    int count = 0;
    while(*p){++count;++p;}
    return count;
}
void pointer_and_array(){
    char ch[100];
    cout<<sizeof(ch)<<endl;
    for(int i=0;i<50;i++)ch[i]='a';
    ch[50]='\0';
    char* p = ch;
    cout<<strlen(ch)<<endl;

}
void deleted_pointer(){
    int* p = new int(10);
    delete p;
    int x = 20;
    p = &x;
    cout<<*p<<endl;
}
int main(){
    //sizeof_array();
   // pointer_and_array();
    deleted_pointer();

}
