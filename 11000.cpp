#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ctime pair<int,int>
using namespace std;

vector<ctime> v;
int N;

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		int s, t;
		cin >> s >> t;
		v.push_back({s, t});
	}
}

void solution(){
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);
	for(int i=1; i<N; i++){
		if(pq.top() <= v[i].first){
			pq.pop();
		}
		pq.push(v[i].second);
	}
	cout << pq.size() << '\n';
}

int main(){
	getInput();
	solution();
	return 0;
}
