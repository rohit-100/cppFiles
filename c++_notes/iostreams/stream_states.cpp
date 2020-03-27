/*
 * any stream has four states
 * 1.good()
 * 2.bad()
 * 3.eof()
 * 4.fail()
 *
 *
 * if stream.bad() is true then nothing can happend 
 *      to move forward simply raise an exception
 *
 * if stream.eof() is true we have reached to the 
 *      end of input , simply return 
 *  
 * if stream.good() is a state when all is going good
 *
 * if stream.fail() happends when some unwanted data of
 *      of different fomate occur while io operation
 *      e.g. 1 2 3 4 5 *
 *          * is not integer 
 *      we can do stream.clear() and put back the last char read 
 *      and place again the stream in fail state and return 
 *
 *
 *
 */



/*
 *              programme description
 *
 *      inputfile  ------ stream_states_file.txt  
 *
 *
 *
 *
 *
 */




/*
 *
 * if we want to automate the raising of excepting while getting stream.bad() true
 * we have to add one line
 * stream.exceptions(stream.exceptions() | ios_base::badbit);
 */



#include<bits/stdc++.h>
using namespace std;

void fill_vector(ifstream& ifs,vector<int>& v,char terminator){
    

    int temp;
    while(ifs >> temp) v.push_back(temp);

    if (ifs.eof())return ;

//     if(ifs.bad()){                    if line   ifs.exceptions(ifs.exceptions() | ios_base::badbit); is added
//         cout<<"bad occur\n";
//        return ;
//     }
    if(ifs.fail()){
        ifs.clear();
        char c;
        ifs >> c;
        cout<<"char "<<c<<" occured\n";
        if(c != terminator){
            ifs.unget();
            ifs.clear(ios::failbit);
        }
    }

    
}

int main(){
    const char* ifn ="stream_states_file.txt";
    ifstream ifs(ifn);
    ifs.exceptions(ifs.exceptions() | ios_base::badbit);
    vector<int> v;
    fill_vector(ifs,v,'$');
    for(int val:v){
        cout<<val<<" ";
    }
}
