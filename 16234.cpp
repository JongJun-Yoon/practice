#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#define intp pair<int,int>
#define MAX 50+1
using namespace std;

int N,L,R;
int A[MAX][MAX];
bool vis[MAX][MAX];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
vector<intp> pos;

void getInput(){
	cin >> N >> L >> R;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> A[i][j];
		}
	}
}

void dfs(int x, int y){
	if(vis[x][y])	return;
	vis[x][y] = true;
	pos.push_back({x,y});
	for(int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(0<=nx && nx<N && 0<=ny && ny<N && !vis[nx][ny]){
			int diff = abs(A[x][y]-A[nx][ny]);
			if(L<=diff && diff<=R){
				dfs(nx,ny);
			}
		}
	}
}

void Print(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}

void Solution(){
	int cnt=0;
	while(1){
		bool move=false;
		for(int i=0; i<MAX; i++)	memset(vis[i],0, sizeof(vis[i]));
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(!vis[i][j]){
					for(int k=0; k<4; k++){
						int nx = i+dx[k];
						int ny = j+dy[k];
						if(0<=nx && nx<N && 0<=ny && ny<N && !vis[nx][ny]){
							int diff = abs(A[i][j]-A[nx][ny]);
							if(L<=diff && diff<=R)	dfs(i,j);
						}
					}
				}
				if(!pos.empty()){
					move=true;
					int avg=0;
					for(auto it:pos)	avg+=A[it.first][it.second];
					avg /= pos.size();
					for(auto it:pos)	A[it.first][it.second] = avg;
					pos.clear();
				}
			}
		}
		if(!move)	break;
		cnt++;
	}
	cout << cnt << '\n';
}

int main(){
	getInput();
	Solution();
	return 0;
}
