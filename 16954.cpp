#include <iostream>
#include <queue>
#define point pair<int,int>
#define SIZE 8
using namespace std;

bool chess[SIZE][SIZE][SIZE+1];
bool visit[SIZE][SIZE][SIZE+1];
point src={SIZE-1,0};
point dest={0,SIZE-1};
int dx[]={0,-1,0,1,0,-1,1,1,-1};
int dy[]={0,0,1,0,-1,1,1,-1,-1};
queue<pair<point,int>> q;

void getInput(){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			char temp;
			cin >> temp;
			if(temp=='#')	chess[i][j][0]=true;
			for(int k=1; (i+k)<SIZE; k++){
				chess[i+k][j][k] = chess[i][j][0];
			}
		}
	}
}

void printWall(){
	cout << '\n';
	for(int k=0; k<=SIZE; k++){
		for(int i=0; i<SIZE; i++){
			for(int j=0; j<SIZE; j++){	
				if(chess[i][j][k])	cout <<  '#';
				else 	cout << '.';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

bool bfs(){
	q.push({src,0});
	visit[src.first][src.second][0]=true;
	while(!q.empty()){
		if(q.front().first==dest)	return true;
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		if(time >= SIZE)	return true;
		q.pop();
		//cout << x << ',' << y << " - " << time << '\n';
		for(int i=0; i<9; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = time + 1;
			if(nt >= SIZE)	nt=SIZE;
			if(0<=nx && nx<SIZE && 0<=ny && ny<SIZE && !visit[nx][ny][nt] && !chess[nx][ny][time] && !chess[nx][ny][nt]){
				q.push({{nx,ny},nt});
				visit[nx][ny][nt]=true;
			}
		}
	}
	return false;
}

int main(){
	getInput();
	cout << bfs() << '\n';
	return 0;
}
