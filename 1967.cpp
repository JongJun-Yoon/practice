#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#define MAX 10000+1
#define intp pair<int,int>
using namespace std;

int N;
int leng[MAX];
vector<intp> tree[MAX];

void getInput(){
	cin >> N;
	int p, c, v;
	for(int i=0; i<N-1; i++){
		cin >> p >> c >> v;
		tree[c].push_back({p,v});
		tree[p].push_back({c,v});
	}
}

void printTree(){
	bool visit[MAX];
	stack<int> st;
	st.push(1);
	while(!st.empty()){
		int now = st.top();
		cout << now << ' ';
		st.pop();
		visit[now]=true;
		for(int i=0; i<tree[now].size(); i++){
			intp next = tree[now][i];
			if(!visit[next.first]){
				st.push(next.first);
			}
		}
	}
}

int main(){
	getInput();
	printTree();
	return 0;
}

