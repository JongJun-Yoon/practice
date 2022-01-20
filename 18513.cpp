#include <iostream>
#include <queue>
#include <set>
#define intp pair<int,int>
#define MAX 100000000+1
using namespace std;
int N,K;
int dx[]={-1,1};
set<int> s;
queue<int> q;

void getInput(){
	cin >> N >> K;
	for(int i=0; i<N; i++){
		int temp;
		cin >> temp;
		q.push(temp);
		s.insert(temp);
	}
}
void bfs(){
	long long sum = 0;
	int dist=1;
	while(!q.empty() && K>0){
		int qsize = q.size();
		while(qsize-- && K>0){
			int pos = q.front();
			q.pop();
			for(int i=0; i<2; i++){
				int npos = pos +dx[i];
				if(s.find(npos) == s.end()){
					sum += dist;
					q.push(npos);
					s.insert(npos);
					K--;
					if(K==0)	break;
				}
			}
		}
		dist++;
	}
	cout << sum << '\n';
}
int main(){
	getInput();
	bfs();
	return 0;
}
