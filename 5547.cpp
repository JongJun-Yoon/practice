#include <iostream>
#define MAX 100+2
using namespace std;

bool map[MAX][MAX];
bool visit[MAX][MAX];
bool chk[MAX][MAX];
int dx[]={0,-1,-1,0,1,1};
int dy1[]={-1,0,1,1,1,0};
int dy2[]={-1,-1,0,1,0,-1};
int W, H;

void dfs(int x, int y){
	if(chk[x][y])	return;
	chk[x][y] = true;
	int nx,ny;
	for(int i=0; i<6; i++){
		nx = x+dx[i];
		if(x%2)	ny = y+dy1[i];
		else		ny = y+dy2[i];
		if(0<=nx&&nx<=H+1&&0<=ny&&ny<=W+1&& !map[nx][ny])	
			dfs(nx,ny);
	}
}

int main(){
	int val;
	cin >> W >> H;

	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			cin >> val;
			if(val){	
				map[i][j] = true;
			}
		}
	}
	dfs(0,0);
	int ans = 0;
	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			if(map[i][j]){
				int nx, ny;
				for(int k=0; k<6; k++){
					nx = i+dx[k];
					if(i%2)	ny=j+dy1[k];
					else	ny=j+dy2[k];
					if(chk[nx][ny])	ans++;
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
