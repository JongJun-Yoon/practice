#include <iostream>
#include <queue>
#include <functional>
#include <set>
#define intp pair<int,int>
#define MAX 100000000+1
using namespace std;
int N,K;
int dx[]={-1,1};
set<int> s;
priority_queue<intp, vector<intp>, greater<intp>> pq;

void getInput(){
	cin >> N >> K;
	for(int i=0; i<N; i++){
		int temp;
		cin >> temp;
		pq.push({0,temp});
		s.insert(temp);
	}
}
void bfs(){
	long long sum = 0;
	while(!pq.empty() && K>0){
		int dist = pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		for(int i=0; i<2; i++){
			int npos = pos +dx[i];
			int ndist = dist+1;
			if(s.find(npos) == s.end()){
				sum += ndist;
				pq.push({ndist,npos});
				s.insert(npos);
				K--;
				if(K==0)	break;
			}
		}
	}
	cout << sum << '\n';
}
int main(){
	getInput();
	bfs();
	return 0;
}
