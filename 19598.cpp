//Exact same question 11000.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ctime pair<int,int>
using namespace std;

int N;
vector<ctime> v;

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		int a, b;
		cin >> a >> b;
		v.push_back({a,b});
	}
}

void solution(){
	getInput();
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);
	for(int i=1; i<N; i++){
		if(pq.top() <= v[i].first){
			pq.pop();
			pq.push(v[i].second);
		}else{
			pq.push(v[i].second);
		}
	}
	cout << pq.size() << '\n';
}

int main(){
	solution();
	return 0;
}
