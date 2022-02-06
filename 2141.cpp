#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
#define INF MAX*10000
#define intp pair<int,int>
using namespace std;

int N;
vector<intp> v(MAX, {INF,INF});

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
}

void sol(){
	vector<long long> s(N, 0);
	s[0] = v[0].second;
	for(int i=1; i<N; i++){
		s[i] = s[i-1] + v[i].second;
	}

	int left = 0, right = N-1;
	int pos = MAX;
	while(left <= right){
		int mid = (left + right) / 2;
		if(s[mid] < s[N-1] - s[mid]){
			left = mid + 1;
		}else{
			right = mid - 1;
			pos = min(pos, v[mid].first);
		}
	}
	cout << pos << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
