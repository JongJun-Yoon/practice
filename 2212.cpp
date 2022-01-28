#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, K;
set<int> s;

void getInput(){
	cin >> N;
	cin >> K;
	for(int i=0; i<N; i++){
		int temp;
		cin >> temp;
		s.insert(temp);
	}
}

void solution(){
	getInput();
	vector<int> v(K);
	int small = *s.begin(), big =  *s.rbegin();
	for(int i=0; i<K; i++){
		v[i] =round(((i+1)*big + (K-i)*small)/(K+1));
	}
	int ans = 0, idx = 0, d = 0;
	for(auto it:s){
		if(idx == K-1){
			d = max(d, abs(v[idx] - it));
		}else{
			if(abs(v[idx] - it) < abs(v[idx+1] - it)){
				d = max(d, abs(v[idx] - it));
			}else{
				ans += d;
				idx++;
				d = 0;
			}
		}
	}
	ans += d;
	cout << ans << '\n';
}

int main(){
	solution();
	return 0;
}
