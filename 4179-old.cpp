#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#define point pair<int,int>
#define mytype pair<point, int>
#define MAX 1000+1
using namespace std;

int R,C, Jx, Jy;
int map[MAX][MAX];
int fire[MAX][MAX];
vector<point> f;
bool vis[2][MAX][MAX];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void getInput(){
	cin >> R >> C;
	cin.ignore();

	for(int i=0; i<R; i++){
		string temp;
		getline(cin,temp);
		for(int j=0; j<C; j++){
			if(temp[j]=='F'){	
				map[i][j] = -1;
				fire[i][j] = 0;
				f.push_back({i,j});
			}
			else if(temp[j]=='.' || temp[j]=='J'){	
				map[i][j] = 1;
				fire[i][j]= 0;
				if(temp[j]=='J'){	
					Jx = i; 
					Jy = j;
				}
			}
			else{
				map[i][j] = 0;
				fire[i][j]=-1;
			}
		}
	}
}

void makeFire(){
	queue<point> q;
	for(auto it:f){	
		q.push(it);
		vis[0][it.first][it.second]=true;
	}
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(0<=nx && nx<R && 0<=ny && ny<C && !vis[0][nx][ny] && fire[nx][ny]!= -1){
				fire[nx][ny]=fire[x][y]+1;
				q.push({nx,ny});
				vis[0][nx][ny]=true;
			}
		}
	}
}



void printMap(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout << fire[i][j] << ' ';
		}
		cout << '\n';
	}

}

void bfs(){
	queue<mytype> q;
	q.push({{Jx,Jy},0});
	vis[1][Jx][Jy]=true;
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();
		if(x==0 || x==R-1 || y==0 || y==C-1){
			cout << t+1 << '\n';
			return;
		}
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			int nt=t+1;
			if(0<=nx && nx<R && 0<=ny && ny<C && !vis[1][nx][ny] && fire[nx][ny]>nt && map[nx][ny]==1){
				q.push({{nx,ny},nt});
				vis[1][nx][ny]=true;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return;
}


int main(){
	getInput();
	makeFire();
	printMap();
	bfs();
	return 0;
}
