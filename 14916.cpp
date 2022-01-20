#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int fcnt = n/5;
	int ans = -1;
	while(fcnt >= 0){
		int rem = n - 5*fcnt;
		if(rem%2 == 0){
			ans = fcnt + rem/2;
			break;
		}else{
			fcnt--;
		}
	}
	cout << ans << '\n';
	return 0;
}
