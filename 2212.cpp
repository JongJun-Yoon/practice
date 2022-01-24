#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
vector<int> v;

void getInput(){
	cin >> N;
	cin >> K;
	for(int i=0; i<N; i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
}

void solution(){
	getInput();
	sort(v.begin(), v.end());
}

int main(){
	solution();
	return 0;
}
