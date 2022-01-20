#include <iostream>
#include <queue>
#include <algorithm>
#define point pair<int,int>
#define MAX 200+1
using namespace std;

int K, W, H;
bool map[MAX][MAX];
int dx[]={-1,0,1,0,-2,-1,1,2,2,1,-1,-2};
int dy[]={0,1,0,-1,1,2,2,1,-1,-2,-2,-1};
bool vis[MAX][MAX];
int ans=-1;

void getInput(){
	cin >> K;
	cin >> W >> H;
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			int temp;
			cin >> temp;
			if(temp==0)	map[i][j]=true;
		}
	}
}

void dfs(point p, int depth){
	cout << p.first << ',' << p.second << '\n';
	if(p.first==H-1 && p.second==W-1){	
		if(ans<0)	ans = depth;
		else		ans = min(ans,depth);
		return;
	}
	vis[p.first][p.second]=true;
	for(int i=0; i<12; i++){
		if(i>=4 && K==0)	continue;
		int nx=p.first+dx[i];
		int ny=p.second+dy[i];
		if(0<=nx && nx<H && 0<=ny && ny<W && !vis[nx][ny] && map[nx][ny]){
			if(i>=4)	K--;
			dfs({nx,ny},depth+1);
			if(i>=4)	K++;
		}
	}
	vis[p.first][p.second]=false;
	return;
}

int main(){
	getInput();
	dfs({0,0},0);
	cout << ans << '\n';
	return 0;
}
