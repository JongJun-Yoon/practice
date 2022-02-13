#include <iostream>
#include <vector>
#define MAX 1000000+1
using namespace std;

int main(){
	vector<bool> v(MAX, true);
	int M, N;
	cin >> M >> N;
	v[1] = false;
	for(int i=2; i<=N; i++){
		if(v[i]){
			for(int j=2*i; j<=N; j+=i){
				v[j] = false;
			}
		}
		if(i >= M && v[i])	cout << i << '\n';
	}
	return 0;
}	
