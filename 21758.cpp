#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, total;
vector<int> v;

void getInput(){
	cin >> N;
	total = 0;
	for(int i=0; i<N; i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
		total += temp;
	}
}

void solution(){
	int ans = 0;
	int val_a = v[0];
	int val_b = 0;
	int val_c = v[N-1];
	int lsum = 0, rsum = total - val_a - val_c;

	for(int i=1; i<N-1; i++){
		int last = val_b;
		val_b = v[i];
		lsum += last;
		rsum -= val_b;
		ans = max(ans, 2*lsum + rsum + 2*val_a);
		ans = max(ans, lsum + rsum + 2*val_b);
		ans = max(ans, lsum + 2*rsum + 2*val_c);
	}


	cout << ans << '\n';
}

int main(){
	getInput();
	solution();
	return 0;
}
