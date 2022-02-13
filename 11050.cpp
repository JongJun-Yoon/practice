#include <iostream>
#include <vector>
#define MAX 10+1
using namespace std;

int dp[MAX][MAX];

int c(int n, int k){
	if(k == 0 || k == n)	return 1;
	if(dp[n][k] != 0)	return dp[n][k];
	return dp[n][k] = c(n-1, k-1) + c(n-1, k);
}

int main(){
	int N, K;
	cin >> N >> K;
	cout << c(N, K) << '\n';
	return 0;
}
