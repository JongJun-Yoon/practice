#include <iostream>
#define MAX 500+1
using namespace std;

int N, CNT=0;
int map[MAX], dp[MAX];

void getInput(){
	cin >> N;
	for(int i=1; i<=N; i++){
		int from, to;
		cin >> from >> to;
		map[from] = to;
		CNT = max(CNT, max(from, to));
	}
}

void print(){
	for(int i=1; i<=12; i++){
		cout << dp[i] << ' ';
	}
	cout << '\n';
}

void sol(){
	int ans = 0;
	for(int j=0; j<N; j++){
		int idx = 1, del = 0;
		for(int j=2; j<=CNT; j++){
			if(map[j] == 0)	continue;
			if(map[idx] < map[j]){
				idx = j;
			}else{
				del = idx;
				dp[j] = del;
			}
		}
		print();
		cout << del << '\n';
		if(del > 0){
			map[del] = 0;
			ans++;
		}else	break;
	}
	cout << ans << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
