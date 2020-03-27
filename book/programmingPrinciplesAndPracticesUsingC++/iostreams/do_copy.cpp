#include<bits/stdc++.h>
using namespace std;
void variation_1(){
    
    string ifn = "temp.txt";
    string ofn = "temp_copy.txt";
    ifstream ifs(ifn.c_str());
    ofstream ofs(ofn.c_str());
    int hour;
    double temp;
    while(ifs >> hour >> temp){
//         cout<<hour<<" "<<temp<<endl;
           ofs << hour<<" "<<temp<<endl;
    }
}
void variation_2(){

    const char* ifn = "temp.txt";
    const char* ofn= "temp_copy.txt";
    ifstream ifs(ifn);
    ofstream ofs(ofn);
    int hour;
    double temp;
    while(ifs >> hour >> temp){
//         cout<<hour<<" "<<temp<<endl;
           ofs << hour<<" "<<temp<<endl;
    }
}

int main(){
    variation_2();
}
