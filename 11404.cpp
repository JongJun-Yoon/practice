#include <iostream>
#define MAX 100+1
#define INF 10000000
using namespace std;

int g[MAX][MAX];
int n, m;

void getInput(){
	cin >> n;
	cin	>> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			g[i][j] = INF;
		}
		g[i][i] = 0;
	}
	for(int i=1; i<=m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c);
	}
}

void print(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(g[i][j] == INF)	cout << "0 ";
			else				cout << g[i][j] << ' ';
		}
		cout << '\n';
	}
}

void floyd(){
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	print();
}

int main(){
	getInput();
	floyd();
	return 0;
}
