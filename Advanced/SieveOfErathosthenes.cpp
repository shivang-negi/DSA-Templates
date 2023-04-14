#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if(n==1) return false;
    for (long long i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

//print all prime factors of a number O(sqrt n)
void primeFactors(long long n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n = n/2;
    }
 
    for (int i = 3; (i*i) <= n; i = i + 2) {
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

//Segmented Sieve (Primes in range [L,R])

void GetPrimes(vector<int>& prime, int R){
    bool c[R + 1];
    memset(c, true, sizeof(c));
    c[1] = false;
    c[0] = false;
    // iterate the loop from 2 till sqrt of R
    for (int i = 2; (i * i) <= R; i++){
        if (c[i] == true){
            // if it is true mark all its multiples as false
            for (int j = i * i; j <= sqrt(R); j = j + i) {
                c[j] = false;
            }
        }
    }
    // storing all the primes in given range in prime array.
    for (int i = 2; i * i <= R; i++){
        if (c[i] == true) {
            prime.push_back(i);
        }
    }
}

void Segmented_Sieve(int L, int R){
    // a dummy array of size R-L+1 is used for tracking the prime numbers in the given range
    bool dummy[R - L + 1];
    //initialise all its elements as true
    memset(dummy, true, sizeof(dummy));
    //here dummy[0] indicates whether low is prime or not similarly dummy[1] indicates whether low+1 is prime or not
    vector<int> prime;
    GetPrimes(prime, R);
    
    for (int i : prime){
        // getting the first index for prime multiples in the given range
        int low = (L/ i);
        // here dummy[0] indicates whether L is prime or not similarly dummy[1] indicates whether low+1 is prime or not   
        if (low <= 1){
            low = i + i;
        }
        else if (L % i){
            low = (low * i) + i;
        }
        else{
            low = (low * i);
        }
        for (int j = low; j <= R; j = j + i){
            dummy[j - L] = false;
        }
    }
   
    for (int i = L; i <= R; i++){
        if (dummy[i - L] == true){
            // if it is true it is a prime number and we print as result
            cout << (i) << " ";
        }
    }
}
