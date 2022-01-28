#include <iostream>
#include <vector>
#define MAX 50000

using namespace std;

vector<int> v(MAX+1,0);
vector<int> r(MAX+1,0);
int N, K;

void print(){
	for(int i=1; i<=N; i++)
		cout << v[i] <<' ' << r[i] << '\n';
}

void getInput(){
	cin >> N >> K;
	for(int i=1; i<=N; i++)
		cin >> v[i];
}

void cal(){
	for(int i=0; i<N;){
		int j = i+1;
		while(j <= N && v[j]%2 == 0)	j++;
		for(int k = i; k < j; k++){
			r[k] = j-i-1;
		}
		i = j;
	}
}


int main(){
	getInput();
	cal();
	print();
	return 0;
}
