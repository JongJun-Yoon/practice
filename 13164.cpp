#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> v;

void getInput(){
	cin >> N >> K;
	for(int i=0; i<N; i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
}

bool cmp(int a, int b){
	return a > b;
}

void solution(){
	int ans = 0;
	vector<int> s;
	for(int i=0; i<N-1; i++){
		s.push_back(v[i+1]-v[i]);
		ans += v[i+1]-v[i];
	}
	sort(s.begin(), s.end(), cmp);
	for(int i=1; i<K; i++){
		ans -= s[i-1];
	}
	cout << ans << '\n';
}

int main(){
	getInput();
	solution();
	return 0;
}
