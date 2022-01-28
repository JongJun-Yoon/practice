#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;

bool win(int n){
	if(n == 1)	return true;
	else if(n == 2)	return false;
	else if(n == 3)	return true;
	else if(v[n] != -1)	return v[n];
	return v[n] = (!win(n-1) || !win(n-3));
}

int main(){
	cin >> N;
	v.assign(N+1,-1);
	if(win(N))	cout << "SK\n";
	else		cout << "CY\n";
	return 0;
}
