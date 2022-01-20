#include <iostream>
#include <string>
using namespace std;

int main(){
	string type1 = "AAAA";
	string type2 = "BB";
	string pol, ans;
	cin >> pol;
	
	int front = -1, end = -1;
	for(int i=0; i<pol.length();){
		if(pol[i] == '.'){
			ans.append(".");
			i++;
		}else{
			front = i;
			while(i<pol.length() && pol[i] != '.')	i++;
			end = i;
			int len = end - front;
			if(len%2 == 1){
				ans = "-1";
				break;
			}else{
				int cnt1 = len/4;
				int cnt2 = len%4/2;
				for(int j=0; j<cnt1; j++)	ans.append(type1);
				for(int j=0; j<cnt2; j++)	ans.append(type2);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
