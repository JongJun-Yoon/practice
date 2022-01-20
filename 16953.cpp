#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int ans = 1;
	while(a < b){
		if(b%10 == 1){
			b /= 10;
			ans++;
		}else if(b%2 == 0){
			b /= 2;
			ans++;
		}else{
			break;
		}
	}
	if(a == b)	cout << ans << '\n';
	else		cout << "-1\n";

	return 0;
}
