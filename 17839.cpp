#include <iostream>
#include <cstring>
#include <queue>
#define MAX 100+1
#define intp pair<int,int>

using namespace std;

int N,M,T;
int map[MAX][MAX];
int cnt[MAX][MAX];
bool vis[MAX][MAX];
queue<intp> q;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void getInput(){
	cin >> N >> M >> T;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> map[i][j];
		}
	}
}

void bfs(){
	q.push({1,1});
	vis[1][1] = true;
	cnt[N][M] = T+1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x==N && y==M){
			break;
		}
		for(int i=0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(0<nx && nx<=N && 0<ny && ny<=M && !vis[nx][ny] && map[nx][ny]!=1){
				q.push({nx,ny});
				vis[nx][ny]=true;
				if(nx==N && ny==M)	cnt[nx][ny]=min(cnt[nx][ny], cnt[x][y]+1);
				else	cnt[nx][ny]=cnt[x][y]+1;	
				if(map[nx][ny]==2){
					cnt[N][M] = min(cnt[N][M], cnt[nx][ny]+(N-nx)+(M-ny));
				}
			}
		}
	}			
	if(cnt[N][M]==T+1)	cout << "Fail\n";
	else				cout << cnt[N][M] << '\n';
}

int main(){
	getInput();
	bfs();
	return 0;
}
