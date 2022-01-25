#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int N, M;
vector<int> crane;
priority_queue<int> box;

void getInput(){
	cin >> N;
	int temp;
	for(int i=0; i<N; i++){
		cin >> temp;
		crane.push_back(temp);
	}
	cin >> M;
	for(int i=0; i<M; i++){
		cin >> temp;
		box.push(temp);
	}
}

void solution(){
	getInput();
	sort(crane.begin(), crane.end(), greater<int>());
	deque<int> dq;
	if(crane[0] < box.top()){
		cout << "-1\n";
		return;
	}
	while(!box.empty()){
		dq.push_back(box.top());
		box.pop();
	}
	int ans = 1;
	vector<int>::iterator it = crane.begin();
	stack<int> st;
	while(!dq.empty()){
		if(it == crane.end()){
			ans++;
			it = crane.begin();
			while(!st.empty()){
				dq.push_front(st.top());
				st.pop();
			}
		}
		if(dq.front() <= *it){
			it++;
		}else{
			st.push(dq.front());
		}
		dq.pop_front();
		if(dq.empty() && !st.empty()){
			it = crane.end();
			while(!st.empty()){
				dq.push_front(st.top());
				st.pop();
			}
		}
	}
	cout << ans << '\n';	
}

int main(){
	solution();
	return 0;
}
