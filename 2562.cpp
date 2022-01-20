#include <iostream>
using namespace std;

int main(){
	int max = -1, pos = 0;
	for(int i=1; i<10; i++){
		int temp;
		cin >> temp;
		if(temp > max){
			max = temp;
			pos = i;
		}
	}
	cout << max << '\n' << pos << '\n';
	return 0;
}
