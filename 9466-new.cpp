#include <iostream>
#include <cstring>
#define MAX 100000+1
using namespace std;

int T, N, cnt;
int student[MAX];
bool visit[MAX], done[MAX];

void dfs(int x){
	visit[x] = true;
	int next = student[x];
	if(!visit[next])	dfs(next);
	else if(!done[next]){
		for(int i=next; i!=x; i=student[i])	cnt++;
		cnt++;
	}
	done[x] = true;
}

int main(){
	cin >> T;
	while(T--){
		memset(visit, 0, sizeof(visit));
		memset(done, 0, sizeof(done));
		cin >> N;
		cnt = 0;
		for(int i = 1; i <= N; i++){
			cin >> student[i];
		}
		for(int i = 1; i <= N; i++){
			if(!visit[i])	dfs(i);
		}
		cout << N - cnt << '\n';
	}
	return 0;
}
