#include <iostream>
#include <vector>
using namespace std;

int n;
vector<long long> v;

void getInput(){
	cin >> n;
	v.assign(n+1, 0);
}

long long fib(int n){
	if(n == 0)	return 0;
	else if(n == 1)	return 1;
	else if(v[n] != 0)	return v[n];
	return v[n] = fib(n-1) + fib(n-2);
}

int main(){
	getInput();
	cout << fib(n) << '\n';
	return 0;
}
