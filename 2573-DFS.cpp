#include <iostream>
#include <cstring>
#define MAX 300+1
using namespace std;

int map[MAX][MAX];
bool vis[MAX][MAX];
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

void dfs(int x, int y){
	int empty=0;
	vis[x][y]=true;
	search++;
	for(int i=0; i<4; i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(0<=nx && nx<N && 0<=ny && ny<M && !vis[nx][ny]){
			if(map[nx][ny]>0)	dfs(nx,ny);
			else				empty++;
		}
	}
	map[x][y] -= empty;
	if(map[x][y]<=0){
		ice--;
		search--;
		map[x][y]=0;
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
					dfs(i,j);
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
