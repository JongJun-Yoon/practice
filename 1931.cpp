#include <iostream>
#include <vector>
#include <algorithm>
#define time pair<int,int>
using namespace std;

int N;
vector<time> v;

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		int s, f;
		cin >> s >> f;
		v.push_back({s,f});
	}
}

bool cmp(time t1, time t2){
	if(t1.second == t2.second){
		return t1.first < t2.first;
	}
	return t1.second < t2.second;
}

void solution(){
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	int last = -1;
	for(auto t:v){
	//	cout << t.first << ',' << t.second << '\n';
		if(t.first > last){
			last = t.second;
			ans++;
		}
	}
	cout << ans << '\n';
}

int main(){
	getInput();
	solution();
	return 0;
}
