#include <iostream>
#include <string>

using namespace std;

int N;
string color;

void getInput(){
	cin >> N;
	cin >> color;
}

void solution(){
	int ans = 1;
	char s = color[0];
	char prev = color[0];
	for(int i=1; i<color.size(); i++){
		if(prev != color[i]){
			prev = color[i];
			if(s != color[i])	ans++;
		}
	}
	cout << ans << '\n';
}

int main(){
	getInput();
	solution();
	return 0;
}
