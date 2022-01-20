#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#define MAX 1000
#define point pair<int,int>
using namespace std;

int N, M;
int map[MAX][MAX];
int group[MAX*MAX], gidx=1;
bool vis[MAX][MAX];
int dx[] = {-1,0,1,0,-1,1,1,-1};
int dy[] = {0,1,0,-1,1,1,-1,-1};

void getInput(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
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
	for(int i=1; i<gidx; i++){
		cout << group[i] << ' ';
	}
	cout << '\n';
}

bool checkRange(int x, int y){
	return (0<=x && x<N && 0<=y && y<M);
}

int dfs(int x, int y, int g){
	int cnt = 1;
	map[x][y] = g;
	vis[x][y] = true;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(checkRange(nx,ny) && !vis[nx][ny] &&	(map[nx][ny] > 0)){
			cnt += dfs(nx, ny, g);
		}
	}
	return cnt;
}

void solution(){
	int ans = -1;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(!vis[i][j] && map[i][j] > 0){
					group[gidx] = dfs(i, j, gidx);
					gidx++;
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] == 0){
				int con = 1;
				set<int> s;
				for(int k=0; k<4; k++){
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(checkRange(nx,ny) && (map[nx][ny] > 0)){
						s.insert(map[nx][ny]);
					}
				}
				for(auto it:s)	con += group[it];
				ans = max(ans, con);
			}
		}
	}
	cout << ans << '\n';
}

int main(){
	getInput();
	solution();
	return 0;
}
