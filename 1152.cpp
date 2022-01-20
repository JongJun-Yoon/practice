#include <iostream>
#include <string>
using namespace std;

int main(){
	string input;
	getline(cin,input);
	int cnt = input.find(' ');
	if(input[0] == ' ')	cnt--;
	if(input[input.size()-1] == ' ')	cnt--;
	cout << cnt + 1 << '\n';
	return 0;
}
