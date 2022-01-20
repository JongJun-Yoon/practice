#include <iostream>
#include <queue>
#include <string>
#define MAX 1000+2
#define point pair<int,int>
#define mytype pair<point,pair<int,bool>>

using namespace std;

int N,M;
bool map[MAX][MAX];
bool vis[MAX][MAX][2];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
queue<mytype> q;

void getInput(){
	cin >> N >> M;
	cin.ignore();
	for(int i=1; i<=N; i++){
		string str;
		getline(cin,str);
		for(int j=0; j<M; j++){
			if(str[j]=='0')	map[i][j+1]=true;
		}
	}
}

void Print(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void bfs(){
	q.push({{1,1},{1,false}});
	vis[1][1][false]=true;
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int l = q.front().second.first;
		bool k = q.front().second.second;
		cout << x << ',' << y <<": "<< l << ' ' << k << '\n';
		if(q.front().first==make_pair(N,M)){
			cout << l << '\n';
			return;
		}
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!vis[nx][ny][k] && map[nx][ny]){
				q.push({{nx,ny}, {l+1,k}});
				vis[nx][ny][k]=true;
			}
			if(!k && !vis[nx][ny][k] && !map[nx][ny]){
				q.push({{nx,ny}, {l+1,true}});
				vis[nx][ny][true]=true;
			}
		}

	}
	cout << "-1\n";
	return;
}

int main(){
	getInput();
	bfs();
	return 0;
}
