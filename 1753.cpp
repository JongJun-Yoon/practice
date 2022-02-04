#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 20000+1
#define INF 16*MAX
#define intp pair<int,int>
using namespace std;

int V, E, K;
vector<intp> g[MAX];

void getInput(){
	cin >> V >> E;
	cin >> K;
	for(int i=1; i<=E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({w,v});
	}
}

void dijk(){
	vector<int> d(V+1, INF);
	priority_queue<intp, vector<intp>, greater<intp>> pq;
	pq.push({0, K});
	d[K] = 0;
	while(!pq.empty()){
		int mnode = pq.top().second;
		int mdist = pq.top().first;
		pq.pop();
		for(int i=0; i<g[mnode].size(); i++){
			int last = g[mnode][i].second;
			int ndist = g[mnode][i].first + mdist;
			if(d[last] > ndist){
				d[last] = ndist;
				pq.push({ndist, last});
			}
		}
	}
	for(int i=1; i<=V; i++){
		if(d[i] == INF)	cout << "INF" << '\n';
		else				cout << d[i] << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	getInput();
	dijk();
	return 0;
}
