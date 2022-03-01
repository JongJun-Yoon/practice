#include <iostream>
#include <vector>
#include <algorithm>
#define intp pair<int,int>
using namespace std;

int N;
vector<intp> v;

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		int from, to;
		cin >> from >> to;
		v.push_back({from, to});
	}
	sort(v.begin(), v.end());
}

void sol(){
	int dp[101], ans = 0;
	for(int i=0; i<N; i++){
		dp[i] = 1;
		for(int j = 0; j<i; j++){
			if(v[i].second > v[j].second){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << N-ans << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
