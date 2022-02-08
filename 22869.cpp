#include <iostream>
#define MAX 5000+1
#define INF 5000000
using namespace std;

int A[MAX];
bool visit[MAX];
int N, K;

void getInput(){
	cin >> N >> K;
	for(int i=1; i<=N; i++)	cin >> A[i];
}

void sol(){
	visit[0] = true;	visit[1] = true;
	for(int i=1; i<N; i++){
		if(!visit[i])	continue;
		for(int j=i+1; j<=N; j++){
			if(visit[j])	continue;
			if((j-i)*(1+abs(A[i]-A[j])) <= K){
				visit[j] = true;
				if(j == N){
					cout << "YES\n";
					return;
				}
			}
		}
	}
	cout << "NO\n";
}

int main(){
	getInput();
	sol();
	return 0;
}
