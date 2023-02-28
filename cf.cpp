#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long mod = 1e9 + 7;
inline void no() {cout<<"NO\n";}
inline void yes() {cout<<"YES\n";}
inline void dbg() {cout<<"here\n";}
inline long long get_bit(long long num, long long n) {return (1 & (num>>n));}
inline long long set_bit(long long n, long long k) {return (n | (1<<k));}
inline long long clear_bit(long long n, long long k) {return (n & (~(1<<k)));}
long long lcm(long long a, long long b){return a / __gcd(a, b) * b;}

void solve() {
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r", stdin);
		freopen("output.txt","w",stdout);
    #endif
	int t;cin>>t;while(t--)
		solve();
	// #ifndef ONLINE_JUDGE
	// freopen("guess.in" ,"r", stdin);
	// freopen("guess.out","w",stdout);
	// #endif
	return 0;
}