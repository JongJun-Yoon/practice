#include <iostream>
#include <queue>

#define MAX 200+1
#define intp pair<int,int>
using namespace std;

int R, C, N;
char map[MAX][MAX];
queue<intp> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};


int main(){
	cin >> R >> C >> N;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> map[i][j];
		}
	}
	int Time = 1;
	queue<intp> q;
	while(Time < N){
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(map[i][j] == 'O')	q.push({i,j});
				else	map[i][j] = 'O';
			}
		}
		Time++;
		if(N <= Time)	break;
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			map[x][y]= '.';
			for(int i=0; i<4; i++){
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0 && nx<R && ny>=0 && ny<C && map[nx][ny] == 'O')	map[nx][ny] = '.';
			}
		}
		Time++;
	}
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}
