#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 25+1
#define intp pair<int,int>

int N;
bool map[MAX][MAX] = {0,};
bool visit[MAX][MAX] = {0,};
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
queue<intp> q;

int bfs(int a, int b){
	int size = 0;
	visit[a][b] = true;
	q.push({a,b});
	size++;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		cout << x << ',' << y << '\n';
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0 && nx<N && ny>=0 && ny<N && map[nx][ny] && !visit[nx][ny]){
				visit[nx][ny] = true;
				q.push({nx,ny});
				size++;
			}
		}
	}
	return size;
}

void numbering(){
	vector<int> home;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] && !visit[i][j]){
				home.push_back(bfs(i,j));
			}
		}
	}
	sort(home.begin(), home.end());
	cout << home.size() << '\n';
	for(auto it:home)	cout << it << '\n';
}

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		int num;
		for(int j=0; j<N; j++){
			scanf("%1d", &num);
			if(num)	map[i][j] = true;
		}
	}
}

int main(){
	getInput();
	numbering();
	return 0;
}
