#include <bits/stdc++.h>
using namespace std;

//print all prime factors of a number
//O(logn) for composite numbers, O(n) otherwise
void primeFactors(int n) {
	int c=2;
	while(n>1) {
		if(n%c==0) {
            cout<<c<<" ";
            n/=c;
		}
		else c++;
	}
}

//print all prime factors of a number O(sqrt n)
void primeFactors(long long n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            cout << i << " ";
            n = n/i;
        }
    }
 
    if (n > 2) cout << n << " ";
}

//To print all prime numbers in range [0,n]      O(n*log(log(n)))
void SieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

int main() {
	int n = 315;
	primeFactors(n);
	return 0;
}
