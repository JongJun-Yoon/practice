#include <iostream>
#include <vector>
#define MAX 20+1

using namespace std;
int C, N;
int cost[MAX], output[MAX];

void getInput(){
	cin >> C >> N;
	for(int i=1; i<=N; i++){
		cin >> cost[i] >> output[i];
	}
}

void sol(){
	
}

int main(){
	getInput();
	sol();
	return 0;
}
