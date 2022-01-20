#include <iostream>
#include <cstring>
#include <queue>
#define point pair<int,int>
#define MAX 300+1
using namespace std;

int map[MAX][MAX];
bool vis[MAX][MAX];
queue<point> q;
int N,M;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int ice=0, search=0;

void getInput(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
			if(map[i][j]>0)	ice++;
		}
	}
}
void printMap(){
	cout << '\n';
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void bfs(int x, int y){
	q.push({x,y});
	vis[x][y]=true;
	search++;
	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		int empty=0;
		q.pop();
		for(int i=0; i<4; i++){
			int nx=a+dx[i];
			int ny=b+dy[i];
			if(0<=nx && nx<N && 0<=ny && ny<M && !vis[nx][ny]){
				if(map[nx][ny]>0){	
					q.push({nx,ny});
					vis[nx][ny]=true;
					search++;
				}
				else				empty++;
			}
		}
		map[a][b] -= empty;
		if(map[a][b]<=0){
			ice--;
			search--;
			map[a][b]=0;
		}
	}
}

void solution(){
	int cnt = 0;
	while(ice>0){
		for(int i=0; i<N; i++)	memset(vis[i],0,sizeof(vis[i]));
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(map[i][j]>0 && !vis[i][j]){	
					search=0;
					cnt++;
					bfs(i,j);
					if(search != ice){
						cout << cnt-1 << '\n';
						return;
					}
				}
			}	
		}
	}
	cout << "0\n";
}

int main(){
	getInput();
	solution();
	return 0;
}
