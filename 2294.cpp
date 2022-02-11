#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
#define INF 100000+1
using namespace std;

int n, k;
vector<int> coin(MAX, 0), dp(INF, INF);

void print(){
	for(int i=1; i<=k; i++)	cout << dp[i] << ' ';
	cout << '\n';
}

void getInput(){
	cin >> n >> k;
	for(int i=0; i<n; i++)	cin >> coin[i];
	sort(coin.begin(), coin.begin()+n);
}

void sol(){
	dp[0] = 0;
	for(int i=0; i<n; i++){
		int m = coin[i];
		dp[m] = 1;
		for(int j=m+1; j<=k; j++){
			dp[j] = min(dp[j], dp[j-m] + 1);
		}
	}
	if(dp[k] == INF)	cout << "-1\n";
	else	cout << dp[k] << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
