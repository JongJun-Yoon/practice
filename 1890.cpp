#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int N;
int map[MAX][MAX];
long long dp[MAX][MAX];

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			cin >> map[i][j];
	}
}

void sol(){
	dp[0][0] = 1;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(dp[i][j] > 0 && !(i == N-1 && j == N-1)){
				if(i+map[i][j] < N){
					dp[i+map[i][j]][j] += dp[i][j];
				}
				if(j+map[i][j] < N){
					dp[i][j+map[i][j]] += dp[i][j];
				}
			}
		}
	}
}

void print(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}
}

int main(){
	getInput();
	sol();
	cout << dp[N-1][N-1] << '\n';
	return 0;
}
