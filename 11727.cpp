#include <iostream>
using namespace std; 

long long dp[1000+1]; 

long long sol(int n){
    if (dp[n] != 0)    return dp[n];
    return dp[n] = (sol(n-1) + 2*sol(n-2)) % 10007;
} 

int main(){
    int n;
    cin >> n;
    dp[1] = 1; dp[2] = 3;
    cout << sol(n) << '\n';
    return 0;
}
