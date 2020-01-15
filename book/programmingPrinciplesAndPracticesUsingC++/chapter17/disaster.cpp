#include<bits/stdc++.h>

using namespace std;

int main(){
    void* p1 = new int ;
    int* p = (int*)p1;
    *p = 10;
    cout<<*p<<endl;
}
