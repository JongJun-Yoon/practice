#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 10000+1

vector<int> v[MAX];
bool visit[MAX];
int cnt;

void dfs(int x){
	visit[x] = true;
	for(int i=0; i<v[x].size(); i++){
		int next = v[x][i];
		if(!visit[next]){
			cnt++;
			dfs(next);
		}
	}
}

int main(){
	int N, M;
	cin >> N >> M;
	while(M--){
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	vector<int> ans;
	int max_val = 0;
	for(int i=1; i<=N; i++){
		cnt = 0;
		memset(visit, false, sizeof(visit));
		dfs(i);
		if(cnt == max_val)
			ans.push_back(i);
		else if(cnt > max_val){
			ans.clear();
			ans.push_back(i);
			max_val = cnt;
		}
	}
	for(int i=0; i<ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
