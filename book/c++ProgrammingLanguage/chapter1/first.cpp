#include<iostream>
using namespace std;

constexpr double square(double x){
    return x*x;
}

bool accept3(){
    int tries = 1;
    while(tries < 4){
        cout<<"do you want to proceed(y or n)?\n";

        char ans = 0;
        cin >> ans;
        switch(ans){
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                cout<<"Sorry, i don't understand that.\n";
                ++tries;
        }
    }
    cout<<"i'll take that for a no \n";
    return false;
}


int main(){
    if(accept3() == true){
        cout << "accepted\n";
    }
    else{
        cout<<"rejected";
    }
    return 0;
}
