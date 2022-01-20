#include <iostream>
#include <queue>

using namespace std;
#define MAX 100
#define intp pair<int,int>
int N,M;
bool map[MAX][MAX];
bool visit[MAX][MAX];
queue<intp> q;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void bfs(){
	q.push({0,0});	
	int cnt[MAX][MAX];
	cnt[0][0] = 1;
	visit[0][0] = true;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if(x == N-1 && y == M-1){	
			cout << cnt[x][y] << '\n';
			return;
		}
		for(int i=0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] && !visit[nx][ny]){
				cnt[nx][ny] = cnt[x][y] + 1;
				visit[nx][ny] = true;
				q.push({nx,ny});
			}
		}
	}
}

int main(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			int num;
			scanf("%1d", &num);
			if(num)	map[i][j] = true;
			else	map[i][j] = false;
		}
	}
	bfs();
	return 0;
}
