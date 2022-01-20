#include <iostream>
#include <queue>

#define MAX 1000+1
#define intp pair<int,int>
using namespace std;

int M,N;
int map[MAX][MAX]={0,};
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int cnt[MAX][MAX]={0,};
bool visit[MAX][MAX]={0,};
queue<intp> q;

void bfsTomato(){
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		visit[x][y] = true;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(0<=nx && nx<N && 0<=ny && ny<M && map[nx][ny]==0 && !visit[nx][ny]){
				visit[nx][ny] = true;
				cnt[nx][ny] = cnt[x][y] + 1;
				q.push({nx,ny});
			}
		}
	}
}

void printOutput(){
	int max=-1;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(cnt[i][j] == 0 && map[i][j] == 0 && !visit[i][j]){
				cout << "-1\n";
				return;
			}
			if(max < cnt[i][j])	max = cnt[i][j];
		}
	}
	cout << max << '\n';
}

void getInput(){
	cin >> M >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
			if(map[i][j]==1){	
				q.push({i,j});
			}
		}
	}
}

int main(){
	getInput();
	bfsTomato();
	printOutput();
	return 0;
}
