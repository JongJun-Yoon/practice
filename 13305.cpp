#include <iostream>
#include <vector>
#include <algorithm>
#define myType pair<long long,int>

using namespace std;
vector<int> city;
vector<myType> v;
int N;

void getInput(){
	cin >> N;
	for(int i=1; i<=N-1; i++){	
		int temp;
		cin >> temp;	//km
		city.push_back(temp);
	}
	for(int i=1; i<=N; i++){
		long long temp;
		cin >> temp;
		v.push_back({temp,i});
	}
}

bool cmp(myType a, myType b){
	if(a.first == b.first){
		return a.second < a.second;
	}
	return a.first < b.first;
}

void solution(){
	sort(v.begin(), v.end(), cmp);
	long long pay = 0; 
	int end = N;
	for(auto it:v){
		int front = it.second;
		long long oil = it.first;
		if(front >= end)	continue;
		for(int i=front; i<end; i++){
			pay += city[i-1]*oil;
		}
		end = front;
		if(front == 1)	break;
	}
	cout << pay << '\n';
}

int main(){
	getInput();
	solution();
	return 0;
}
