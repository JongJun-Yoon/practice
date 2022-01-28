#include <iostream>
#include <vector>
using namespace std; 

vector<vector<long long>> dp;
int step[300+1], N;

void getInput(){
	cin >> N;
    for(int i=0; i<N; i++){
        cin >> step[i];
		vector<long long> v(2,0);
		dp.push_back(v);
    }
}
 
long long sol(){
	if(N == 1)	return step[0];
	dp[0][0] = step[0];
	dp[1][0] = step[1];	dp[1][1] = step[1]+dp[0][0];
	for(int i=2; i<N; i++){
		dp[i][0] = step[i] + max(dp[i-2][0],dp[i-2][1]);
		dp[i][1] = step[i] + dp[i-1][0];
	}
	return max(dp[N-1][0], dp[N-1][1]);
}

int main(){
	getInput();
	cout << sol() << '\n';
	return 0;
}
