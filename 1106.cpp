#include <iostream>
#include <algorithm>
#define CITY 20
#define COST 1000
using namespace std;

int C, N;
int cost[CITY], output[CITY];
int dp[100*COST + 1];

void print(){
	for(int i=1; i<=C; i++){
		cout << dp[i] << ' ';
	}
	cout << '\n';
}

void getInput(){
	cin >> C >> N;
	for(int i=0; i<N; i++){
		cin >> cost[i] >> output[i];
	}
}

void sol(){
	for(int i=1; i<=100*COST; i++){
		for(int j=0; j<N; j++){
			if(i % cost[j] == 0){
				dp[i] = max(dp[i], (i / cost[j]) * output[j]);
			}
			if(i-cost[j] > 0){
				dp[i] = max(dp[i], dp[i-cost[j]] + output[j]);
			}
		}
		if(dp[i] >= C){
			cout << i << '\n';
			return;
		}
	}
}

int main(){
	getInput();
	sol();
	return 0;
}
