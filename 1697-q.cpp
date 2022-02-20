#include <iostream>
#include <queue>
#define MAX 100000+1
using namespace std;

int N, K;
bool visit[MAX];

void getInput(){
	cin >> N >> K;
}

void sol(){
	queue<int> q;
	q.push(N);
	int sec = 0;
	while(!q.empty()){
		int cnt = q.size();
		while(cnt--){
			int now = q.front();
			visit[now] = true;
			cout << sec << ":" << now << '\n';
			if(now == K){
				cout << sec << '\n';
				return;
			}
			q.pop();
			if(now+1 < MAX && !visit[now+1])
				q.push(now+1);
			if(now-1 >= 0 && !visit[now-1])
				q.push(now-1);
			if(now*2<MAX && !visit[now*2])
				q.push(now*2);
		}
		sec++;
	}
}

int main(){
	getInput();
	sol();
	return 0;
}
