#include <iostream>
#define MAX 1000000007
using namespace std;


long long** mul(long long** a, long long** b){
        long long** c = new long long* [2];
        for(int i=0; i<2; i++)
                c[i] = new long long[2];
        c[0][0] = (a[0][0]*b[0][0]+a[0][1]*b[1][0])%MAX;
        c[0][1] = (a[0][0]*b[0][1]+a[0][1]*b[1][1])%MAX;
        c[1][0] = (a[1][0]*b[0][0]+a[1][1]*b[1][0])%MAX;
        c[1][1] = (a[1][0]*b[0][1]+a[1][1]*b[1][1])%MAX;
        return c;
}

int main(){
        long long n;    cin >> n;
        long long** a;
        a = new long long* [2];
        for(int i=0; i<2; i++){
                a[i] = new long long[2];
        }
        a[0][0] = 1;    a[0][1] = 1;
        a[1][0] = 1;    a[1][1] = 0;
        long long** c;
        c = new long long* [2];
        for(int i=0; i<2; i++){
                c[i] = new long long[2];
        }
        c[0][0] = 1;    c[0][1] = 0;
        c[1][0] = 0;    c[1][1] = 1;

        while(n > 0){
                if(n % 2 == 1){
                        c = mul(a, c);
                }
                a = mul(a, a);
                n = n / 2;
        }
        cout << c[0][1] << '\n';
        return 0;
}
