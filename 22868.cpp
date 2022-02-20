#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 10000+1
using namespace std;

int N, M;
vector<int> node[MAX];
int S, E;
bool visit[MAX];
int before[MAX];
int ans = 0;

void getInput(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for(int i=1; i<=N; i++){
		sort(node[i].begin(), node[i].end());
	}
	cin >> S >> E;
}

void bfs(int from, int to){
	queue<int> q;
	q.push(from);	visit[from] = true;
	while(!q.empty()){
		int cnt = q.size();
		while(cnt--){
			int now = q.front();	q.pop();
			cout << ans << ":" << now << '\n';
			if(now == to){
				return;
			}
			for(int i=0; i<node[now].size(); i++){
				int next = node[now][i];
				if(!visit[next] && next > 0){
					q.push(next);
					visit[next] = true;
					before[next] = now;
				}
			}
		}
		ans++;
	}
}

void sol(){
	bfs(S, E);
	memset(visit, false, MAX*sizeof(bool));
	int node = E;
	for(int i=0; i<ans; i++){
		visit[node] = true;
		node = before[node];
	}
	bfs(E, S);
	cout << ans << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
