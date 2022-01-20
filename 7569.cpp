#include <iostream>
#include <queue>

#define MAX 100+1
#define intp pair<int,int>
#define intple pair<intp,int>
using namespace std;

int M,N,H;
int map[MAX][MAX][MAX]={0,};
int dx[]={-1,0,1,0,0,0};
int dy[]={0,1,0,-1,0,0};
int dz[]={0,0,0,0,1,-1};
int cnt[MAX][MAX][MAX] ={0,};
bool visit[MAX][MAX][MAX]={0,};
queue<intple> q;

void bfsTomato(){
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		visit[x][y][z] = true;
		q.pop();
		for(int i=0; i<6; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			int nz = z+dz[i];
			if(0<=nx && nx<N && 0<=ny && ny<M && 0<=nz && nz<H){
				if(map[nx][ny][nz]==0 && !visit[nx][ny][nz]){
					visit[nx][ny][nz] = true;
					cnt[nx][ny][nz] = cnt[x][y][z] + 1;
					q.push({{nx,ny},nz});
				}
			}
		}
	}
}

void printOutput(){
	int max=-1;
	for(int k=0; k<H; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(cnt[i][j][k] == 0 && map[i][j][k] == 0 && !visit[i][j][k]){
					cout << "-1\n";
					return;
				}
				if(max < cnt[i][j][k])	max = cnt[i][j][k];
			}
		}
	}
	cout << max << '\n';
}

void getInput(){
	cin >> M >> N >> H;
	for(int k=0; k<H; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){ 
				cin >> map[i][j][k];
				if(map[i][j][k]==1){	
					q.push({{i,j},k});
				}
			}
		}
	}
}

int main(){
	getInput();
	bfsTomato();
	printOutput();
	return 0;
}
