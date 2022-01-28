#include <iostream>
#include <vector>
using namespace std;

int T, N, M;
vector<vector<int>> vv;

void init(){
	for(int i=0; i<30; i++){
		vector<int> v(i+1,0);
		vv.push_back(v);
	}
}

int combi(int m, int n){
	if(m == n || n == 0)	return 1;
	else if(vv[m][n] != 0)	return vv[m][n];
	return vv[m][n] = combi(m-1,n) + combi(m-1,n-1);
}

int main(){
	init();
	cin >> T;
	while(T--){
		cin >> N >> M;
		cout << combi(M, N) << '\n';
	}
	return 0;
}
