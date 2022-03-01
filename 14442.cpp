#include <iostream>
#include <queue>
#include <string>
#define MAX 1000
#define pos pair<int,int>
#define myT pair<int,pos>
using namespace std;

bool map[11][MAX][MAX];
bool visit[11][MAX][MAX];
int N, M, K;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void getInput(){
	cin >> N >> M >> K;
	cin.ignore();
	for(int i=0; i<N; i++){
		string str;
		getline(cin, str);
		for(int j=0; j<M; j++){
			if(str[j] == '0')	map[0][i][j] = true;
			else				map[0][i][j] = false;
			for(int b=1; b<=K; b++)
				map[b][i][j] = map[0][i][j];
		}
	}
}

void print(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << map[0][i][j] << ' ';
		}
		cout << '\n';
	}
}

void sol(){
	queue<myT> q;
	q.push({K, {0,0}});
	visit[K][0][0] = true;
	int dist = 1;
	while(!q.empty()){
		int cnt = q.size();
		while(cnt--){
			int x = q.front().second.first;
			int y = q.front().second.second;
			int chance = q.front().first;
			q.pop();
			if(x == N-1 && y == M-1){
				cout << dist << '\n';
				return;
			}
			for(int i=0; i<4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(0<=nx && nx<N && 0<=ny && ny<M){
					if(map[chance][nx][ny] && !visit[chance][nx][ny]){
						q.push({chance, {nx, ny}});
						visit[chance][nx][ny] = true;
					}else if(chance > 0 && !visit[chance-1][nx][ny]){
						map[chance-1][nx][ny] = true;
						q.push({chance-1, {nx, ny}});
						visit[chance-1][nx][ny] = true;
					}
				}
			}
		}
		dist++;
	}
	cout << "-1\n";
}

int main(){
	getInput();
	sol();
	return 0;
}
