#include <iostream>
#define MAX 31
using namespace std;

int pascal[MAX][MAX];
int n, k;

void getInput(){
	cin >> n >> k;
}

void sol(){
	for(int i=1; i<=n; i++){
		pascal[i][1] = 1;
		pascal[i][i] = 1;
		for(int j=2; j<i; j++){
			pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
		}
	}
	cout << pascal[n][k] << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
