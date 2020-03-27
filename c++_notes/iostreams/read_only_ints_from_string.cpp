
/*
 *
 * input file used -------------->      input.txt
 *

 */






#include<bits/stdc++.h>
using namespace std;


void skip_bad_chars(ifstream& ifs){
    char ch;
    while(true){
        ifs >> ch;
        if(ifs.eof()){
            return ;
        }
        if(isdigit(ch)){
            ifs.unget();
            return;
        }
        
    }
}


void read_ints(ifstream& ifs,vector<int>& ints){
    int x;

    while(true){
        ifs >> x;
//         cout<<"true";
        if(ifs.good()){
            ints.push_back(x);
            continue;
        }
        if(ifs.eof())break;

        if(ifs.fail()){
            ifs.clear();                //clear the error state of ifs and ready for more input beacuse the state get currupted due to failing
            ifs.sync();                 //clear the input buffer
            skip_bad_chars(ifs);
        }

    }
}


void print_vector(const vector<int>& ints){
    for(int val:ints){
        cout<<val<<" ";
    }
    cout<<endl;
}
int main(){
    const char* file = "input.txt";
    ifstream ifs(file); 
    if(!ifs){
        cout<<"failed to open the file";
        exit(1);
    }
    vector<int> ints;
    read_ints(ifs,ints);
    print_vector(ints);
//     cout<<ints.size()<<endl;
}
