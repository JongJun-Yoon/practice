#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 100+1
using namespace std;

vector<vector<string>> v;

void init(){
	for(int i=0; i<MAX; i++){
		vector<string> s(i+1, "1");
		v.push_back(s);
	}
}

string add(string a, string b){
	string c;
	if(a.length() > b.length()){
		return add(b, a);
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	bool carry = false;
	for(int i=0; i < a.length(); i++){
		string one(1, a[i]);
		string two(1, b[i]);
		int s = stoi(one) + stoi(two);
		if(carry)	s += 1;
		if(s >= 10){
			carry = true;
			s -= 10;
		}else	carry = false;
		c += to_string(s);
	}
	for(int i=a.length(); i < b.length(); i++){
		string two(1, b[i]);
		int s = stoi(two);
		if(carry)	s += 1;
		if(s >= 10){
			carry = true;
			s -= 10;
		}else	carry = false;
		c += to_string(s);
	}
	if(carry)	c+= "1";
	reverse(c.begin(), c.end());
	return c;
}

string sol(int n, int m){
	if(m == n || m == 0)	return "1";
	if(v[n][m].compare("1") != 0)	return v[n][m];
	return v[n][m] = add(sol(n-1, m), sol(n-1,m-1));
}

int main(){
	init();
	int n, m;
	cin >> n >> m;
	cout << sol(n, m) << '\n';
	return 0;
}
