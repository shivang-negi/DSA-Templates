#include <bits/stdc++.h>
using namespace std;

// Function to calculate a^b mod n
long long modulo_expo(long long a, long long b, long long n){
	long long x=1, y=a; 
	while (b > 0) {
		if (b%2 == 1) {
			x = (x*y) % n; 
		}
		y = (y*y) % n;
		b /= 2;
	}
	return x % n;
}
//END



/* Iterative Function to calculate (x^y)%p
in O(log y) */
unsigned long long power(unsigned long long x,int y, int p) {
	unsigned long long res = 1;
	x = x % p; 
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;

		y = y >> 1; 
		x = (x * x) % p;
	}
	return res;
}

unsigned long long modInverse(unsigned long long n,int p) {
	return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
	if (n < r)
		return 0;
	if (r == 0)
		return 1;

	unsigned long long fac[n + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % p;

	return (fac[n] * modInverse(fac[r], p) % p
			* modInverse(fac[n - r], p) % p)% p;
}
//END



//Function to calculate facorial%p
int power(int x, unsigned int y, int p) {
    int res = 1; 
    x = x % p; 
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
 
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int a, int p) {
    return power(a, p - 2, p);
}
 
int modFact(int n, int p) {
    if (p <= n)
        return 0;
 
    int res = (p - 1);
    for (int i = n + 1; i < p; i++)
        res = (res * modInverse(i, p)) % p;
    return res;
}
//END


int main() {
	int n = 10, r = 2, p = 13;
	cout << "Value of nCr % p is "<< nCrModPFermat(n, r, p);
	cout << modFact(25, 10);
	return 0;
}
