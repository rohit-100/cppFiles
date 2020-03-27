#include<bits/stdc++.h>
using namespace std;


class Student{
    private:
        string name,email;
        int roll;
    public:
        Student(string _name,string _email,int _roll):name(_name),email(_email),roll(_roll){}
        
        friend ostream& operator<< (ostream& ost,const Student& val){
            ost <<"name = "<<val.name<<", email = "<<val.email<<", roll "<<val.roll<<endl;
            return ost;
        }
        string to_string(){
            ostringstream oss;
            
            oss << Student(name,email,roll); 
            return oss.str();
        }
};


int main(){
    Student rohit("rohit","rohitkumarsaw21@gmail.com",47);

    string repr = rohit.to_string();
    cout<<repr<<endl;
    cout<<rohit;
     
}
