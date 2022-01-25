#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	string str;
	cin >> str;
	vector<char> v;
	v.push_back(str[0]);
	int i = 1;
	while(K > 0){
		while(0 < K && i < N && !v.empty() && v.back() < str[i]){
			v.pop_back();
			K--;
		}
		if(K == N-i){
			i = N;
			break;
		}
		v.push_back(str[i++]);
	}
	while(i < N){
		v.push_back(str[i++]);
	}
	for(auto it:v) cout << it;
	cout << '\n';
	return 0;
}
