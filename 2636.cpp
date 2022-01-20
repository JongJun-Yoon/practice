#include <iostream>
#include <cstring>
#include <vector>
#define intp pair<int,int>
#define MAX 100+1
using namespace std;

bool map[MAX][MAX];
bool vis[MAX][MAX];
int row,col,cheese;
vector<intp> pos;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void getInput(){
	int val;
	cheese=0;
	cin >> row >> col;
	for(int i=1; i<=row; i++){
		for(int j=1; j<=col; j++){
			cin >> val;
			if(val==1){	
				map[i][j]=true;
				cheese++;
			}
		}
	}
}

void dfs(int x, int y){
	if(vis[x][y])	return;
	vis[x][y]=true;
	for(int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(0<=nx && nx<=row+1 && 0<=ny && ny<=col+1 && !vis[nx][ny]){
			if(map[nx][ny]){
				pos.push_back({nx,ny});
				vis[nx][ny]=true;
			}
			else
				dfs(nx,ny);
		}
	}
}

void Print(){
	for(int i=1; i<=row; i++){
		for(int j=1; j<=col; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}


void Solution(){
	int time=0;
	while(cheese > 0){
		time++;
		pos.clear();
		for(int i=0; i<MAX; i++)	memset(vis[i],0,sizeof(vis[i]));
		dfs(0,0);
		if(cheese==pos.size())	break;
		cheese -= pos.size();
		for(auto it:pos)	map[it.first][it.second]=false;
	}
	cout << time << '\n';
	cout << pos.size() << '\n';
}
int main(){
	getInput();
	Solution();
	return 0;
}
