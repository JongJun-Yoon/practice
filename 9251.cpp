#include <iostream>
#include <vector>
#include <string>
#define MAX 1000+1
using namespace std;
string a, b;
int dp[MAX][MAX];

void getInput(){
	cin >> a;
	cin >> b;
}

void print(){
	for(int i=1; i <= a.length(); i++){
		for(int j=1; j <= b.length(); j++){
			cout << dp[i][j] << ' ';
		}cout << '\n';
	}
}

void sol(){
	for(int i=1; i <= a.length(); i++){
		for(int j=1; j <= b.length(); j++){
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if(a[i-1] == b[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
		}
	}
	print();
	cout << dp[a.length()][b.length()] << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
