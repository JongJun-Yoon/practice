#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> tip;

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		int temp;
		cin >> temp;
		tip.push_back(temp);
	}
}

bool cmp(int a, int b){
	return a > b;
}

void countTip(){
	sort(tip.begin(), tip.end(), cmp);
	long long pay = 0;
	for(int i=0; i<N; i++){
		if((tip[i] - i) > 0)
			pay += (tip[i]-i);
	}
	cout << pay << '\n';
}
int main(){
	getInput();
	countTip();
	return 0;
}
