#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
	int T, K;
	cin >> T;
	while(T--){
		cin >> K;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for(int i=0; i<K; i++){
			int temp; cin >> temp;
			pq.push(temp);
		}
		long long ans = 0;
		while(pq.size() > 1){
			long long one = pq.top();	pq.pop();
			long long two = pq.top();	pq.pop();
			ans += one + two;
			pq.push(one + two);
		}
		cout << ans << '\n';
	}
	return 0;
}
