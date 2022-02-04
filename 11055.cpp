#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

int N;
vector<int> A(MAX, 0);

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++)	cin >> A[i];
}

void print(vector<int> v){
	for(int i=0; i<N; i++)	cout << v[i] << ' ';
	cout << '\n';
}

void sol(){
	vector<int> dp(N,0);	//dp[x] == 0~x increase sum
	dp[0] = A[0];
	int ans = A[0];
	for(int i=1; i<N; i++){
		int sum = 0;
		for(int j=0; j<i; j++){
			if(A[j] < A[i]){
				sum = max(sum, dp[j]);
			}
		}
		dp[i] = sum + A[i];
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
