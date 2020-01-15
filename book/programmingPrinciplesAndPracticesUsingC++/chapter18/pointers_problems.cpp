#include<bits/stdc++.h>
using namespace std;


void null_pointer_problem(){
    int x = 17;
    int* p = 0;
    *p = 7  ;  // segmentation fault

    int* q;
    *q = 10; // segmentation fault
    cout<<*p<<endl;
    /*
        the main problem is that the pointer p is not pointing to somewhere meanningful variable.
        so assignment to that memory location produces segmentation fault;
        




       typically this types of problems occurs when there is some code in between the initialization and the use


       always test a pointer is null ? before use
       
       int* p = fct_that_can_return_a_null_pointer();
       
       if( p == 0){
            do something
        }
        else{
            *p = 7;

        }


        void fnt(int* p){
            if(p == 0){
                
                // do something

            }
            else{
                //use p
                *p = 7;
            }
        }

        

    */
}

vector<int>*  pointer_to_a_local_variable(){
    vector<int>* x = new vector<int>(10,3);
    return x;
}

int main(){
   // null_pointer_problem();
    vector<int>* ff  = pointer_to_a_local_variable();
    (*ff)[5]=10;
    for(int i=0;i<ff->size();++i)cout<<(*ff)[i]<<" ";
    cout<<endl;
    //ff[5]=4;
    //cout<<ff[5]<<endl;
        
}
