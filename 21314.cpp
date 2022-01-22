#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	string str;
	cin >> str;
	string big, sml;
	stack<char> st;
	for(int i=0; i<str.length(); i++){
		if(str[i] == 'M'){
			st.push(str[i]);
		}else{
			big.append("5");
			sml.append("1");
			int len = st.size();
			for(int j=0; j<len; j++){
				big.append("0");
				sml.append("0");
				st.pop();
			}
			sml.pop_back();
			sml.append("5");
		}
	}
	if(!st.empty()){
		big.append("1");
		sml.append("1");
		for(int i=1; i<st.size(); i++){
			big.append("0");
			sml.append("0");
		}
	}
			
	cout << big << '\n' << sml << '\n';
	return 0;
}
