#include <iostream>
#include <vector>
#define MAX 20+1

using namespace std;
int C, N;
int cost[MAX], output[MAX];
int dp[MAX][1001];

void getInput(){
	cin >> C >> N;
	for(int i=1; i<=N; i++){
		cin >> cost[i] >> output[i];
	}
}

void sol(){
	for(int i=0; i<=N; i++){
		for(int j=0; j<=1000; j++){
			dp[i][j] = max(dp[i-1][j], dp[]);
		}
	}
}

int main(){
	getInput();
	sol();
	return 0;
}
