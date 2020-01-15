// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		string s;
// 		cin>>s;
// 		long ans=0;
// 		int n=s.length();
// 		vector<int>pr;
// 		pr.push_back(0);
// 		for(int i=1;i<n;i++){
// 			if(s[i-1]=='0')pr.push_back(pr.back()+1);
// 			else pr.push_back(0);
// 		}
// 		//for(int val:pr)cout<<val<<" ";cout<<endl;
// 		for(int i=n-1;i>=0;i--){
// 			int num=0;
// 			int j;
// 			int pow=1;
// 			for( j=i;j>=max(0,i-25);j--){
				
				
// 				num+=(s[j]-'0')*pow;
// 				pow*=2;
// 				cout<<num<<j<<i<<endl;
// 				//cout<<i<<" "<<j<<" "<<num<<" "<<1+floor(log2(num))<<endl;
// 				if(num>0 and pr[j]+i-j+1 >= num){cout<<j<<" "<<i<<endl;ans++;}
// 				//cout<<"num = "<< num<<" "<< i<<j <<endl;
// 			}

			
// 		}
// 		cout<<ans<<endl;
// 	}
// }

 #include <iostream>
using namespace std;
int main() {
int t;
cin >> t;
while(t--){
string a; cin >> a;
int len = 0, ats = 0;
for(int i = 0; i < a.size(); i++) if(a[i] == '1'){
int sk = 0;
for(int j = i; j < a.size() && j-i <= 20; j++){
sk = sk*2 + (a[j] == '1');
if(sk-(j-i+1) <= len) ats++;
}
len = 0;
}else len++;
cout << ats << "\n";
}
}