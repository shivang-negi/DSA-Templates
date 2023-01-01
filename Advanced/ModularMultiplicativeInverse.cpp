#include<bits/stdc++.h>
using namespace std;

//when gcd of A and M is 1
int modInverse(int A, int M) {
    int m0 = M;
    int y = 0, x = 1;
 
    if (M == 1) return 0;
 
    while (A > 1) {
        int q = A / M;
        int t = M;
        M = A % M, A = t;
        t = y; 
        y = x - q * y;
        x = t;
    }
 
    if (x < 0) x += m0;
    return x;
}


int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int power(int x, unsigned int y, unsigned int M);
 
// when M is prime
void modInverseM(int A, int M) {
    cout<<"Modular multiplicative inverse is "<<power(A, M - 2, M);
}
 
int power(int x, unsigned int y, unsigned int M) {
    if (y == 0) return 1;
 
    int p = power(x, y / 2, M) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}

int main() {
    int A = 3, M = 11;
    cout<<"Modular multiplicative inverse is "<<modInverse(A, M);
    return 0;
}