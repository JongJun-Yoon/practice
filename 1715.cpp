//13975.cpp same
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0; i<N; i++){
		int temp; cin >> temp;
		pq.push(temp);
	}
	int ans = 0;
	while(pq.size() > 1){
		int one = pq.top();	pq.pop();
		int two = pq.top();	pq.pop();
		ans += one + two;
		pq.push(one + two);
	}
	cout << ans << '\n';
	return 0;
}
