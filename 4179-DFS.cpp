#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define point pair<int,int>
#define mytype pair<point,int>
#define MAX 1000+1
using namespace std;

int R,C;
int Jx,Jy;
vector<vector<int>> map[MAX];
bool fvis[MAX][MAX][MAX];
bool jvis[MAX][MAX][MAX];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void getInput(){
	cin >> R >> C;
	cin.ignore();
	for(int i=0; i<R; i++){
		string temp;
		getline(cin,temp);
		vector<int> v;
		for(int j=0; j<C; j++){
			if(temp[j]=='F'){	
				v.push_back(-1);
			}
			else if(temp[j]=='.' || temp[j]=='J'){	
				v.push_back(1);
				if(temp[j]=='J'){	
					Jx = i; 
					Jy=j;
				}
			}
			else	v.push_back(0);
		}
		map[0].push_back(v);
	}
	for(int k=0; k<MAX; k++){
		map[k]=map[0];
	}
}

void printMap(){
	for(int i=0; i<MAX; i++){
		cout << '\n' << i << "sec\n";
		for(int j=0; j<R; j++){
			for(int k=0; k<C; k++)
				cout << map[i][j][k] << ' ' ;
			cout << '\n';
		}
	}
}

void fire_dfs(int x, int y, int depth){
	if(depth==max(R,C))	return;
	fvis[depth][x][y]=true;
	for(int i=0; i<4; i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		int nd =depth+1;
		if(0<=nx && nx<R && 0<=ny && ny<C && !fvis[nd][nx][ny] && map[depth][nx][ny] ==1){
			for(int k=nd; k<max(R,C); k++)	map[k][nx][ny]=-1;
			fire_dfs(nx,ny,nd);
		}
	}
}

int jdfs(int x, int y, int depth){
//	cout << x << ',' << y << ';' << depth << '\n';
	if(x==0 || x==R-1 || y==0 || y==C-1)	return depth+1;
	jvis[depth][x][y]=true;
	for(int i=0; i<4; i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		int nd =depth+1;
		if(0<=nx && nx<R && 0<=ny && ny<C && !jvis[nd][nx][ny] && map[depth][nx][ny] ==1){
			return jdfs(nx,ny,nd);
		}
	}
	return -1;
}


int main(){
	getInput();
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[0][i][j]==-1)	fire_dfs(i,j,0);
		}
	}
	int ans = jdfs(Jx,Jy,0);
	if(ans>=0)	cout << ans << '\n';
	else		cout << "IMPOSSIBLE\n";
	return 0;
}
