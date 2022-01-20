#include <iostream>
#include <queue>
#include <algorithm>
#define intp pair<int,int>
#define MAX 100000+1
using namespace std;
int sec[MAX];
bool vis[MAX];
priority_queue<intp, vector<intp>, greater<intp>> pq;

int main(){
	int N,K;
	cin >> N >>K;
	pq.push({0,N});
	vis[N]=true;
	while(!pq.empty()){
		int time = pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		if(pos==K)	cout << time << '\n';
		if(pos*2<MAX && !vis[pos*2]){
			pq.push({time, pos*2});
			vis[pos*2]=true;
		}
		if(pos+1<MAX && !vis[pos+1]){
			pq.push({time+1, pos+1});
			vis[pos+1]=true;
		}
		if(pos-1>=0 && !vis[pos-1]){
			pq.push({time+1, pos-1});
			vis[pos-1]=true;
		}
	}
	return 0;
}
