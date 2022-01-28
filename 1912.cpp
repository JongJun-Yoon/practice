#include <iostream>
#include <climits>
#include <vector>
#define MAX 100000
using namespace std;

int N;
vector<int> v(MAX, 0);
vector<int> dp(MAX, 0);

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> v[i];
	}
}

int sol(){
	int ans = v[0];
	dp[0] = v[0];
	for(int i=1; i<N; i++){
		dp[i] = max(dp[i-1]+v[i], v[i]);
		ans = max(ans, dp[i]);
	}

	return ans;
}

int main(){
	getInput();
	cout << sol() << '\n';
	return 0;
}
