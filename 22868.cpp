#include <iostream>
#include <set>
#include <queue>
#define MAX 10000+1
using namespace std;

int N, M;
int S, E;
set<int> v[MAX];
bool visit[MAX];

void getInput(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int temp;
		cin >> temp;
		v[i].insert(temp);
		v[temp].insert(i);
	}
	cin >> S >> E;
}

void bfs(){
	int length = 0;
	queue<int> q;
	q.push(S);
	visit[S] = true;
	while(q.empty()){
		int qsize = q.size();
		length++;
		while(qsize--){
			int node = q.front();
			visit[node] = true; 
			q.pop();
			for(int i=0; i<v[node].size(); i++){
				int adj = v[next][i];
				if(!visit[adj])	q.push(adj);
			}
		}
	}

	cout << length << '\n';
}

int main(){
	getInput();
	bfs();
	return 0;
}
