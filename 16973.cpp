#include <iostream>
#include <queue>
#define MAX 1000+1
#define point pair<int,int>

using namespace std;
int N, M, H, W;
bool map[MAX][MAX];
bool vis[MAX][MAX];
point src,dest;
queue<pair<point,int>> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void getInput(){
	cin >> N >> M;
	int temp;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> temp;
			if(temp == 1){	
				map[i][j]=true;
			}
		}
	}
	cin >> H >> W >> src.first >> src.second >> dest.first >> dest.second;
}

bool checkWall(point p, int dir){
	int x=p.first;
	int y=p.second;
	if(!(0<x && x+H<=N+1 && 0<y && y+W<=M+1))	return false;
	if(dir==3){
		for(int i=x; i<x+H; i++){
			if(map[i][y])	return false;
		}
	}else if(dir==1){
		for(int i=x; i<x+H; i++){
			if(map[i][y+W-1])	return false;
		}
	}else if(dir==0){
		for(int j=y; j<y+W; j++){
			if(map[x][j])	return false;
		}
	}else{
		for(int j=y; j<y+W; j++){
			if(map[x+H-1][j])	return false;
		}
	}
	return true;
}

void bfs(){
	q.push({src,0});
	vis[src.first][src.second]=true;
	while(!q.empty()){
		if(q.front().first==dest){	
			cout << q.front().second<< '\n';
			return;
		}
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();
		cout << x << ',' << y << ": " << d <<'\n';
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!vis[nx][ny] && checkWall({nx,ny},i)){
				q.push({{nx,ny},d+1});
				vis[nx][ny]=true;
			}
		}
	}
	cout << "-1\n";
	return;
}

int main(){
	getInput();
	bfs();
	return 0;
}
