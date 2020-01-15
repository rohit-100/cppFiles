#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout<<sizeof(char)<<endl;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(int*)<<endl;
    cout<<sizeof(char*)<<endl;
    cout<<sizeof(double*)<<endl;
    cout<<sizeof(double)<<endl;
    cout<<sizeof(long long int)<<endl;
    cout<<sizeof(long int)<<endl;
    cout<<sizeof(bool)<<endl;
    cout<<sizeof(4*2.3)<<endl;
    cout<<sizeof(float)<<endl;
    vector<int>v(1000);
    cout<<"size of vector is "<<sizeof(v)<<endl;

}
