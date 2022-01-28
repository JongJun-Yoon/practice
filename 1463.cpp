#include <iostream>
#include <vector>
#define MAX 1000000+1
using namespace std;

vector<int> v(MAX, 0);

int sol(int x){
	if(x <= 1)	return 0;
	if(v[x] != 0)	return v[x];
	int a = MAX;
	if(x%3 == 0){
		a = min(a, 1+sol(x/3));
	}
	if(x%2 == 0){
		a = min(a, 1+sol(x/2));
	}
	return v[x] = min(a, 1+sol(x-1));
}

int main(){
	int N;
	cin >> N;
	cout << sol(N) << '\n';
	return 0;
}
