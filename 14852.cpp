#include <iostream>
#define MAX 1000000+1
#define mod 1000000007
using namespace std;

long long dp[MAX][2];
int N;

void getInput(){
	cin >> N;
}

void sol(){
	dp[1][0] = 2;	
	dp[2][0] = 7;	dp[2][1] = 1;
	for(int i=3; i<=N; i++){
		dp[i][1] = (dp[i-1][1] + dp[i-3][0]) % mod;
		dp[i][0] = (dp[i-1][0]*2 + dp[i-2][0]*3 + dp[i][1]*2)%mod;
	}
	cout << dp[N][0] << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
