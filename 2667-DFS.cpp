#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 25+1

int N, cnt=0;
bool map[MAX][MAX]={0,};
bool visit[MAX][MAX]={0,};
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x, int y){
	cnt++;
	visit[x][y] = true;
	for(int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>=0 && nx<N && ny>=0 && ny<N && map[nx][ny] && !visit[nx][ny]){
			dfs(nx, ny);
		}
	}
}

void numbering(){
	vector<int> ans;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] && !visit[i][j]){
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}
	sort(ans.begin(),ans.end());
	cout << ans.size() << '\n';
	for(auto it:ans)	cout << it << '\n';
}

void getInput(){
	cin >> N;
    for(int i=0; i<N; i++){
    	int num;
        for(int j=0; j<N; j++){
        	scanf("%1d", &num);
            if(num) map[i][j] = true;
        }
    }
}

int main(){
	getInput();
	numbering();
	return 0;
}
