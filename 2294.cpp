#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
#define INF 100000+1
using namespace std;

int n, k;
vector<int> coin(MAX, 0), dp(MAX, INF);

void getInput(){
	cin >> n >> k;
	for(int i=0; i<n; i++)	cin >> coin[i];
	sort(coin.begin(), coin.begin() + n);
}

void sol(){
	if(k < coin[0]){
		cout << "-1\n";
		return;
	}
}

int main(){
	getInput();
	sol();
	return 0;
}
