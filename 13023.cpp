#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 2000

using namespace std;
int N, M;
vector<int> con[MAX];
bool vis[MAX];
bool ans=false;

void getInput(){
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a >> b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
}

void dfs(int x, int depth){
	if(depth==4){
		ans=true;
		return;
	}
	vis[x]=true;
	for(int i=0; i<con[x].size(); i++){
		if(!vis[con[x][i]])	
			dfs(con[x][i], depth+1);
	}
	vis[x]=false;
	return;
}

bool solution(){
	for(int i=0; i<N && !ans; i++){
		memset(vis, 0, sizeof(bool)*MAX);
		dfs(i,0);
	}
	return ans;
}


int main(){
	getInput();
	if(solution())	cout << "1\n";
	else			cout << "0\n";
	return 0;
}
