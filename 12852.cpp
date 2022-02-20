#include <iostream>
#include <queue>
#include <stack>
#define MAX 1000000+1
using namespace std;

int N;
bool visit[MAX];
int before[MAX];

void getInput(){
	cin >> N;
}

void sol(){
	queue<int> q;
	q.push(N);
	visit[N] = true;
	int ans = 0;
	while(!q.empty()){
		int cnt = q.size();
		while(cnt--){
			int now = q.front();	q.pop();
			if(now == 1){
				cout << ans << '\n';
				stack<int> st;
				st.push(1);
				while(ans--){
					st.push(before[st.top()]);
				}
				while(!st.empty()){
					cout << st.top() << ' ';
					st.pop();
				}
				return;
			}
			if(now%3 == 0 && !visit[now/3]){
				q.push(now/3);
				visit[now/3] = true;
				before[now/3] = now;
			}
			if(now%2 == 0 && !visit[now/2]){
				q.push(now/2);
				visit[now/2] = true;
				before[now/2] = now;
			}
			if(now-1 >= 0 && !visit[now-1]){
				q.push(now-1);
				visit[now-1] = true;
				before[now-1] = now;
			}
		}
		ans++;
	}
}

int main(){
	getInput();
	sol();
	return 0;
}
