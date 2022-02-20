#include <iostream>
#define MAX 100

using namespace std;
int N;
bool map[MAX][MAX];

void getInput(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}
}

void printMap(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void sol(){
	for(int k=0; k<N; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(!map[i][j]){
					if(map[i][k] && map[k][j]){
						map[i][j] = true;
					}
				}
			}
		}
	}
	printMap();
}

int main(){
	getInput();
	sol();
	return 0;
}
