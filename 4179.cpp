#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define point pair<int,int>
#define MAX 1000+2

using namespace std;
int R,C;
string map[MAX];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void getInput(){
	cin >> R >> C;
	cin.ignore();
	for(int i=0; i<R; i++){
		getline(cin, map[i]);
	}
}

void printMap(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout << map[i][j];
		}
		cout << '\n';
	}
}

void bfs(){
	queue<point> fq, jq;
	bool visit[MAX][MAX];
	for(int i=0; i<R; i++){
		memset(visit[i], 0, sizeof(visit[i]));
		for(int j=0; j<C; j++){
			if(map[i][j]=='F')	fq.push({i,j});
			if(map[i][j]=='J')	jq.push({i,j});
		}
	}
	int time = 0;
	while(1){
		time++;
		int fqsize=fq.size();
		while(fqsize--){
			int x = fq.front().first;
			int y = fq.front().second;
			fq.pop();
			for(int k=0; k<4; k++){
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(0<=nx && nx<R && 0<=ny && ny<C && map[nx][ny]!='#' && map[nx][ny]!='F'){
					fq.push({nx,ny});
					map[nx][ny]='F';
				}
			}
		}
		int jqsize=jq.size();
		if(jqsize==0)	break;
		while(jqsize--){
			int x = jq.front().first;
			int y = jq.front().second;
			jq.pop();
			if(x==0 || x==R-1 || y==0 || y==C-1){
				cout << time << '\n';
				return;
			}
			for(int k=0; k<4; k++){
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(0<=nx && nx<R && 0<=ny && ny<C && !visit[nx][ny] && map[nx][ny]!='#' && map[nx][ny]!='F'){
					jq.push({nx,ny});
					visit[nx][ny]=true;
				}
			}

		}
	}
	cout << "IMPOSSIBLE\n";
	return;
}



int main(){
	getInput();
	bfs();
	return 0;
}
