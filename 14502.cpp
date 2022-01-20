#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 8+2
#define intp pair<int,int>
using namespace std;

int N, M;
int map[MAX][MAX];
int temp[MAX][MAX];
bool vis[MAX][MAX];
bool sel[MAX][MAX];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
vector<intp> zero;
vector<intp> virus;
vector<vector<intp>> wall;


void getInput(){
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> map[i][j];
			if(map[i][j] == 0)		zero.push_back({i,j});
			else if(map[i][j] == 2)	virus.push_back({i,j});	
		}
	}
}

void makeWall(){
	vector<intp> pick;
	for(int i=0; i<zero.size()-2; i++){
		pick.push_back({zero[i].first,zero[i].second});
		for(int j=i+1; j<zero.size()-1; j++){
			pick.push_back({zero[j].first,zero[j].second});
			for(int k=j+1; k<zero.size(); k++){
				pick.push_back({zero[k].first,zero[k].second});
				wall.push_back(pick);
				pick.pop_back();
			}
			pick.pop_back();
		}
		pick.pop_back();
	}
	/*
	for(auto it1:wall) {
		for(auto it2:it1)
			cout << it2.first <<',' << it2.second << ' ';
		cout << '\n';
	}
	*/
}

void dfs(int x, int y){
	if(vis[x][y])	return;
	vis[x][y] = true;
	temp[x][y] = 2;
	for(int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(0<nx && nx<=N && 0<ny && ny<=M && !vis[nx][ny] && temp[nx][ny]==0){
			dfs(nx,ny);
		}
	}
}

int cntzero(){
	int ans = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(temp[i][j] == 0)	ans++;
		}
	}
	return ans;
}

void solution(){
	getInput();
	makeWall();
	int max = -1;
	for(auto it1:wall){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				temp[i][j] = map[i][j];
			}
		}
		for(int i=0; i<MAX; i++){
			memset(vis[i], 0, MAX*sizeof(vis[i]));
		}
		for(auto it2:it1){
			temp[it2.first][it2.second] = 1;
		}
		for(auto it:virus){
			dfs(it.first, it.second);
		}
		if(max < cntzero())	max = cntzero();
	}
	cout << max << '\n';
}

int main(){
	solution();
	return 0;
}
