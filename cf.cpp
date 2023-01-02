#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
long long gcd(long long a, long long b);
long long upper_bound(long long arr[], long long n, long long x);
inline void no() {cout<<"NO\n";}
inline void yes() {cout<<"YES\n";} 

void solve() {
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	int t;cin>>t;while(t--)
		solve();
	return 0;
}

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);}
long long upper_bound(long long arr[], long long n, long long x) { 
	if(n==1) return (x>=arr[0]);
	long long l = 0, r = n - 1;
	while(l<=r) {
		long long mid = (l+r)/2;
		if(arr[mid]==x) {
			if(mid<(n-1) && arr[mid+1]==x) l = mid+1;
			else return mid+1; 
		}
		else if(x<arr[mid]) r = mid - 1;
		else l = mid + 1;
	}
	return l;}