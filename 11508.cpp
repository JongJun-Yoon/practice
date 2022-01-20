#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> p;

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		int temp;	cin >> temp;
		p.push_back(temp);
	}
}

bool cmp(int a, int b){
	return a > b;
}

void solution(){
	sort(p.begin(), p.end(), cmp);
	long long total = 0;
	for(int i=1; i<=N; i++){
		if(i%3 != 0){
			total += p[i-1];
		}
	}
	cout << total << '\n';
}
	
int main(){
	getInput();
	solution();		
	return 0;
}
