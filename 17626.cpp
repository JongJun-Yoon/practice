#include <iostream>
#include <cmath>
#include <vector>
#define MAX 50000+1
using namespace std;

vector<int> v(MAX,0);

int lag(int n){
	if(n == 0)	return 0;
	if(n == pow((int)sqrt(n),2))	return 1;
	if(v[n] != 0)	return v[n];
	int rt = (int)sqrt(n);
	int m = MAX;
	for(int i = rt; i > 0; i--){
		m = min(m, lag(n-pow(i,2)));
		if(m == 1)	break;
	}
	return v[n] = 1 + m;
}

int main(){
	int n;
	cin >> n;
	cout << lag(n) << '\n';
	return 0;
}
