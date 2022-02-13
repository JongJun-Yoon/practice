#include <iostream>
#define NMAX 100
#define KMAX 10000
using namespace std;

int n, k;
int v[NMAX], dp[KMAX+1];

void print(){
	for(int i=1; i<=k; i++)	cout << dp[i] << ' ';
	cout << '\n';
}

void getInput(){
	cin >> n >> k;
	for(int i=0; i<n; i++)	cin >> v[i];
}

void sol(){
	dp[0] = 1;
	for(int i=0; i<n; i++){
		for(int j=v[i]; j<=k; j++){
			dp[j] += dp[j-v[i]];
		}
	}
	cout << dp[k] << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
