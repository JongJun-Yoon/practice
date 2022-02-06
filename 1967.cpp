#include <iostream>
#include <map>
#define MAX 10000+1
#define intp pair<int,int>
using namespace std;

int N;
map<int, pair<intp, intp>> tree;

void getInput(){
	cin >> N;
	int p, c, v;
	for(int i=0; i<N-1; i++){
		cin >> p >> c >> v;
		if(tree[p].first == make_pair(0,0)){
			tree[p].first = {c, v};
		}else{
			tree[p].second = {c, v};
		}
	}
}

void print(int n){
	cout << n << ' ';
	int left = tree[n].first.first;
	int right = tree[n].second.first;
	if(left != 0)	print(left);
	if(right != 0)	print(right);
}

void sol(){
	print(1);
	int ans = 0;
	
	
}

int main(){
	getInput();
	sol();
	return 0;
}

