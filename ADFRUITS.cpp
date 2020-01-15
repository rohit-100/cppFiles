#include<bits/stdc++.h>
using namespace std;


string get(string s1,string s2){
	string ans = s1;
	int i=0,j=0;
	for(;i<s1.length() and j<s2.length();){
		if(s1[i]==s2[j]){
			i++;
			j++;
		}else i++;
	}
	ans+=s2.substr(j,s2.length()-j);
	return ans;
}

int main(){
	string line;
	while(getline(cin,line)){
		int deli=line.find_first_of(" ");
		string s1=line.substr(0,deli);
		string s2 = line.substr(deli+1,line.length()-1-deli);
		//cout<<s1<<" "<<s2<<endl;


		string ans1=get(s1,s2);
		string ans2=get(s2,s1);
		ans1.length()<ans2.length()?cout<<ans1<<endl:cout<<ans2<<endl;
	}
}