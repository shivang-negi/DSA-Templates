#include <bits/stdc++.h>
using namespace std;

//print all prime factors of a number
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
