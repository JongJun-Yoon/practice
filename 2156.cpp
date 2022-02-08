#include <iostream>
#define MAX 10000+2
using namespace std;
int n;
int arr[MAX];
int dp[MAX][3];

void getInput(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
}

void print(){
	for(int i=0; i<3; i++){
		for(int j=1; j<=n; j++){
			cout << dp[j][i] << ' ';
		}cout << '\n';
	}
}

void sol(){
	dp[1][0] = 0;	dp[1][1] = arr[1];	dp[1][2] = 0;
	for(int i=2; i<=n+1; i++){
		dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
		dp[i][1] = dp[i-1][0] + arr[i];
		dp[i][2] = dp[i-1][1] + arr[i];
	}
	cout << dp[n+1][0] << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
