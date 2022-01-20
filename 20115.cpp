#include <iostream>
using namespace std;

void solution(){
	int N;	cin >> N;
	int max = -1;
	float sum = 0;
	for(int i=0; i<N; i++){
		int temp;	cin >> temp;
		if(temp > max)	max = temp;
		sum += temp;
	}
	sum = (sum + max)/2;
	cout << sum << '\n';
}

int main(){
	solution();
	return 0;
}
