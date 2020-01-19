#include<bits/stdc++.h>
using namespace std;
string add(string a,string b){
    int n = a.length();
    int m = b.length();
    if(m>n)swap(a,b);
    n = a.length();
    m = b.length();
    int j = m-1;
    int inhand = 0;
    int i;
    for(i=n-1;i>=0 and j>=0;i--,j--){
        int temp =  (a[i]-'0'+b[j]-'0'+inhand);
        if(temp/10)inhand = 1;
        a[i]=temp%10+'0';
    }
    if(inhand and i<0){
        a = to_string(inhand)+a;
    }
    else if(inhand) a[i]=a[i]+1;
    return a;

}
string sub(string a,string b){
    int n = a.length();
    int m = b.length();
    if(m>n)swap(a,b);
    n = a.length();
    m = b.length();
    int j = m-1;
    int inhand = 0;
    int i;
    for(i = n-1;i>=0 and j>=0;i--,j--){
        int temp = a[i]-b[j]-inhand;
        if(temp < 0){
            inhand = 1;
            a[i] = (char)temp+10+'0';
        }
        else{
            inhand = 0;
            a[i] = (char)temp+'0';
        }

    }
    return a;
}
string div(string a,int b){

}

int main(){

    int t=1;
    while(t--){
        string a,b;
        cin>>a>>b;
        //string n = div(add(a,b),2);
        //string m = sub(a-n);
        cout<<add(a,b)<<endl;
        cout<<sub(a,b)<<endl;

    }
}
