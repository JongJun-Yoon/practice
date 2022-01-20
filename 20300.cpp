#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000000000000+1
using namespace std;

int N;
vector<long long> t;

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		long long temp;
		cin >> temp;
		t.push_back(temp);
	}
}

void solution(){
	sort(t.begin(), t.end());
	long long M = 0;
	if(N%2 == 1){
		M = t[N-1];
		for(int i=0; i<(N-1)/2; i++){
			M = max(M, t[i]+t[N-2-i]);
		}
	}else{
		for(int i=0; i<N/2; i++){
			M = max(M, t[i]+t[N-1-i]);
		}
	}
	cout << M << '\n';
}

int main(){
	getInput();
	solution();
	return 0;
}
