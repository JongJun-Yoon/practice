#include <iostream>
#include <vector>
#define MAX 15
using namespace std;

int N, cnt = 0;
int map[MAX];

bool move(int x){
	for(int i=0; i<x; i++){
		if(map[x] == map[i] || x-i == abs(map[x]-map[i]))	return false;
	}
	return true;
}

void nq(int ord){
	if(ord == N){
		cnt++;
		return;
	}else{
		for(int i=0; i<N; i++){
			map[ord] = i;
			if(move(ord))	nq(ord+1);
		}
	}
}

void sol(){
	cin >> N;
	nq(0);
	cout << cnt << '\n';
}

int main(){
	sol();
	return 0;
}
