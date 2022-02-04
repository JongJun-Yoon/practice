#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1500000+1
#define intp pair<int,int>
#define intt pair<intp,int>
using namespace std;

int N;
vector<intt> v;

bool cmp(intt a, intt b){
	return a.first.second < b.first.second;
}

void getInput(){
	cin >> N;
	v.assign(N+1, {{0,0},0});
	for(int i=1; i<=N; i++){
		int t, p;
		cin >> t >> p;
		v[i].first.first = i;
		v[i].first.second = i + t -1;
		v[i].second= p;
	}
	sort(v.begin(), v.end(), cmp);
}

void sol(){
	int j = 1;
	vector<int> dp(N+1, 0);
	for(int i=1; i<=N; i++){
		if(v[j].first.second > i){
			dp[i] = dp[i-1];
			continue;
		}
		while(v[j].first.second == i){
			int start = v[j].first.first;
			int finish = i;
			int price = v[j].second;
			dp[finish] = max(dp[finish], dp[finish-1]);
			dp[finish] = max(dp[finish], price + dp[start-1]); 
			j++;
		}
	}
	cout << dp[N] << '\n';
}

int main(){
	getInput();
	sol();
	return 0;
}
