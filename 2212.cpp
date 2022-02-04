#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> v;

void getInput(){
	cin >> N;
	cin >> K;
	for(int i=0; i<N; i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
}

void solution(){
	getInput();
	vector<int> d;
	for(int i=0; i<N-1; i++){
		d.push_back(v[i+1]-v[i]);
	}
	sort(d.begin(), d.end());
	int ans = 0;
	for(int i=0; i<N-K; i++){
		ans += d[i];
	}
	cout << ans << '\n';
}

int main(){
	solution();
	return 0;
}
