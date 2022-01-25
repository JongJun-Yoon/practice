#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define move pair<int,int>
#define work pair<move, int>
using namespace std;

int N, C, M;
priority_queue<work, vector<work>, greater<work>> pq;

void getInput(){
	cin >> N >> C;
	cin >> M;
	int a, b, c;
	for(int i=0; i<M; i++){
		cin >> a >> b >> c;
		pq.push({{b, a}, c});
	}
}

void solution(){
	getInput();
	vector<int> v(N+1,0);
	int fr, to, w;
	long long ans = 0;
	while(!pq.empty()){
		to = pq.top().first.first;
		fr = pq.top().first.second;
		w = pq.top().second;
		for(int i=fr; i<to; i++){
			w = min(w, C-v[i]);
		}
		for(int i=fr; i<to; i++){
			v[i] += w;
		}
		ans += w;
		pq.pop();
	}
	cout << ans << '\n';
}

int main(){
	solution();
	return 0;
}
