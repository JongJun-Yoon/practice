#include <iostream>
#define MAX 10000
using namespace std;

int n;
int dp[3][MAX], stker[2][MAX];

void sol(){
	dp[0][0] = stker[0][0];	
	dp[1][0] = stker[1][0];	
	dp[2][0] = 0;
	dp[0][1] = stker[0][1] + dp[1][0];
	dp[1][1] = stker[1][1] + dp[0][0];

	for(int i=2; i<n; i++){
		dp[0][i] = stker[0][i] + max(dp[1][i-1], max(dp[0][i-2], dp[1][i-2]));
		dp[1][i] = stker[1][i] + max(dp[0][i-1], max(dp[0][i-2], dp[1][i-2]));
	}
	cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
}


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n;
		for(int i=0; i<2; i++){
			for(int j=0; j<n; j++)
				cin >> stker[i][j];
		}
		sol();
	}
	return 0;
}
