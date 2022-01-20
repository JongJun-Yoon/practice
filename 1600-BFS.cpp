#include <iostream>
#include <queue>
#include <algorithm>
#define point pair<int,int>
#define kpoint pair<int,point>
#define mydata pair<int,kpoint>
#define MAX 200+1
using namespace std;

int K, W, H;
bool map[MAX][MAX];
int dx[]={-1,0,1,0,-2,-1,1,2,2,1,-1,-2};
int dy[]={0,1,0,-1,1,2,2,1,-1,-2,-2,-1};
bool vis[MAX][MAX][30+1];
int ans=-1;
queue<mydata> q;

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

void bfs(){
	q.push({0, {0,{0,0}}});
	vis[0][0][0]=true;
	while(!q.empty()){
		int depth = q.front().first;
		int jump = q.front().second.first;
		int x = q.front().second.second.first;
		int y = q.front().second.second.second;
		q.pop();
		cout << x << ',' << y << ' ' << jump << ' ' << depth<<'\n';
		if(x==H-1 && y==W-1){
			ans=depth;
			return;
		}
		for(int i=0; i<12; i++){
			int nx, ny, nj=jump;
			if(i>=4){
				if(jump>=K)	continue;
				nj = jump+1;
			}
			nx=x+dx[i];
			ny=y+dy[i];
			if(0<=nx && nx<H && 0<=ny && ny<W && !vis[nx][ny][nj] && map[nx][ny]){
				q.push({depth+1, {nj,{nx,ny}}});
				vis[nx][ny][nj]=true;
			}
		}
	}
}

int main(){
	getInput();
	bfs();
	cout << ans << '\n';
	return 0;
}
