#include <iostream>
#define mod 1000000007
using namespace std;

long long** mul(long long** a, long long** b){
	long long** c = new long long*[2];
	c[0] = new long long[2];
	c[1] = new long long[2];

	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			c[i][j] = 0;
			for(int k=0; k<2; k++){
				c[i][j] = (c[i][j] + a[i][k]* b[k][j]) % mod;
			}
		}
	}
	return c;
}

int main(){
	int n;	cin >> n;
	long long** ans;
	long long** a;
	ans = new long long*[2];
	a = new long long*[2];
	for(int i=0; i<2; i++){
		ans[i] = new long long[2];
		a[i] = new long long[2];
	}
	ans[0][0] = 1;	ans [0][1] = 0;
	ans[1][0] = 0;	ans [1][1] = 1;
	a[0][0] = 1;	a [0][1] = 1;
	a[1][0] = 1;	a [1][1] = 0;

	while(n>0){
		if(n%2 == 1){
			ans = mul(a, ans);
			n--;
		}else{
			a = mul(a, a);
			n /= 2;
		}
	}
	cout << ans[1][0] << '\n';

	return 0;
}
