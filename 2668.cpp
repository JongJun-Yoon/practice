#include <iostream>
#include <set>
#include <cstring>
#define MAX 100+1
using namespace std;

int arr[MAX];
int N;
bool vis[MAX];
set<int> s;
set<int> ans;

void getInput(){
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> arr[i];
}

int dfs(int x){
	if(vis[x])	return 0;
	if(x==arr[x]){
		s.insert(x);
		return 1;
	}
	vis[x]=true;
	s.insert(arr[x]);
	return 1+dfs(arr[x]);
}

void solution(){
	int max_num = -1;
	for(int i=1; i<=N; i++){
		memset(vis,0,MAX*sizeof(bool));
		s.clear();
		if(dfs(i) == s.size()){
			ans.insert(i);
		}
	}
	cout << ans.size() << '\n';
	for(auto it: ans)	cout << it << '\n';
}

int main(){
	getInput();
	solution();
	return 0;
}
