#include <iostream>
#include <vector>
#define intp pair<int,int>
#define MAX 20+1
#define INF 100000
using namespace std;

vector<intp> v(MAX, {0,0});
vector<intp> dp(MAX, {INF, INF});
int N, K;

void getInput(){
	cin >> N;
	for(int i=1; i<N; i++){	
		cin >> v[i].first >> v[i].second;
	}
	cin >> K;
}

void print(){
	for(int i=1; i<=N; i++){
		cout << dp[i].first << ' ';
	}
	cout << '\n';
	for(int i=1; i<=N; i++){
		cout << dp[i].second << ' ';
	}

}

void sol(){
	dp[1].first = 0;	dp[1].second = 0;
	for(int i=1; i<N; i++){
		dp[i+1].first = min(dp[i+1].first, dp[i].first + v[i].first);
		if(i+2 <= N)
			dp[i+2].first = min(dp[i+2].first, dp[i].first + v[i].second);
		if(i+3 <= N){
			dp[i+3].second = min(dp[i+2].second + v[i+2].first, dp[i+1].second + v[i+1].second);
			dp[i+3].second = min(dp[i+3].second, dp[i].first + K);
		}
	}
	cout << min(dp[N].first, dp[N].second) << '\n';
	print();
}

int main(){
	getInput();
	sol();
	return 0;
}
