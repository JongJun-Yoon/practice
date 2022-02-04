#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1000+1
#define INF 100000000
#define intp pair<int,int>
using namespace std;

int N, M;
int src, dst;
vector<intp> g[MAX];

void getInput(){
	cin >> N;
	cin >> M;
	for(int i=1; i<=M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
	}
	cin >> src >> dst;
}

void dijkstra(){
	priority_queue<intp, vector<intp>, greater<intp>> pq;
	pq.push({0, src});
	vector<int> d(N+1, INF);
	while(!pq.empty()){
		int mid = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		if(d[mid] < dist)	continue;
		for(int i=0; i<g[mid].size(); i++){
			int next = g[mid][i].first;
			int ndist = g[mid][i].second + dist;
			if(d[next] > ndist){
				d[next] = ndist;
				pq.push({ndist, next});
			}
		}
	}
	cout << d[dst] << '\n';
}
	
int main(){
	getInput();
	dijkstra();
	return 0;
}
