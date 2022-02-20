#include <iostream>
#include <queue>
#include <vector>
#define MAX 100000+1
#define intp pair<int,int>
#define intt pair<int,intp>
using namespace std;

int N, K;
bool visit[MAX];

void getInput(){
	cin >> N >> K;
}

void sol(){
	priority_queue<intt, vector<intt>, greater<intt>> pq;
	pq.push({0,{abs(N-K), N}});
	while(!pq.empty()){
		int cnt = pq.size();
		while(cnt--){
			int now = pq.top().second.second;
			int sec = pq.top().first;
			visit[now] = true;
			cout << sec << ":" << now << '\n';
			if(now == K){
				cout << sec << '\n';
				return;
			}
			pq.pop();
			if(now+1 < MAX && !visit[now+1])
				pq.push({sec+1,{abs(now+1-K), now+1}});
			if(now-1 >= 0 && !visit[now-1])
			pq.push({sec+1,{abs(now-1-K), now-1}});
			if(now*2<MAX && !visit[now*2])
			pq.push({sec+1,{abs(now*2-K), now*2}});
		}
	}
}

int main(){
	getInput();
	sol();
	return 0;
}
