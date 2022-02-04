#include <iostream>
#define MAX 1500000+1
using namespace std;

int N;
int t[MAX], p[MAX];
int dp[MAX+1];

void getInput(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> t[i] >> p[i];
	}
}

void sol(){
	for(int i=1; i<=N; i++){
		dp[i+t[i]] = max(dp[i+t[i]], dp[i] + p[i]);
		dp[i+1] = max(dp[i+1], dp[i]);
	}
	cout << dp[N+1] << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
