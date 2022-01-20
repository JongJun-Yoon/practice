#include <iostream>
#include <queue>
#define point pair<int,int>
#define MAX 1000+1
using namespace std;

int n,m;
int map[MAX][MAX];
int cnt[MAX][MAX];
bool vis[MAX][MAX];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
point dest;
queue<point> q;

void getInput(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> map[i][j];
			if(map[i][j] == 2)	dest = {i,j};
		}
	}
}

void print(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cout << cnt[i][j] << ' ';
		}
		cout << '\n';
	}
}

void bfs(){
	q.push(dest);
	vis[dest.first][dest.second] = true;
	cnt[dest.first][dest.second] = 0;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(0<nx && nx<=n && 0<ny && ny<=m && !vis[nx][ny] && map[nx][ny]){
				q.push({nx,ny});
				vis[nx][ny] = true;
				cnt[nx][ny] = cnt[x][y]+1;
			}
		}
	}
}

void dfs(int x, int y){
	if(vis[x][y])	return;
	vis[x][y]=true;
	cnt[x][y]=-1;
	for(int i=0; i<4; i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(0<nx && nx<=n && 0<ny && ny<=m && !vis[nx][ny] && map[nx][ny])
			dfs(nx, ny);
	}
}

void findShort(){
	bfs();
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(map[i][j] && !vis[i][j])		dfs(i,j);
		}
	}
}


int main(){
	getInput();
	findShort();
	print();
	return 0;
}
