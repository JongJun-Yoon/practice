#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define MAX 100000+1

using namespace std;

int n;
int v[MAX];
bool visit[MAX], team[MAX];

void getInput(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> v[i];
	}
}

void dfs(int x){
	stack<int> st;
	vector<int> g;
	visit[x] = true;
	st.push(x);
	g.push_back(x);
	while(!st.empty()){
		int next = v[st.top()];
		if(visit[next]){
			break;
		}
		st.pop();
		visit[next] = true;
		st.push(next);
		g.push_back(next);
	}
	int idx = 0;
	while(!st.empty() && idx < g.size()){
		if(v[st.top()] == g[idx]){
			for(int i=idx; i<g.size(); i++){
				visit[g[i]] = true;
				team[g[i]] = true;
			}
			st.pop();
		}else{
			idx++;
		}
	}
}

int main(){
	int T;
	cin >> T;
	while(T--){
		getInput();
		memset(team, 0, sizeof(team));
		memset(visit, 0, sizeof(visit));
		for(int i=1; i<=n; i++){
			if(!visit[i])	dfs(i);
		}
		int cnt = 0;
		for(int i=1; i<=n; i++){
			if(!team[i])	cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
