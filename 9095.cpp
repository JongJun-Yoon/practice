#include <iostream>

using namespace std; 

long long DP[12]; 

long long sol(int n){
    if(DP[n] != 0)    return DP[n];
    return DP[n] =   sol(n-1) + sol(n-2)  + sol(n-3);
} 

int main(){
    int T, n;
    cin >> T;
    DP[1] = 1; DP[2] = 2; DP[3] = 4;
    while(T--){
        cin >> n;
        cout << sol(n) << '\n';
    }
    return 0;
}
