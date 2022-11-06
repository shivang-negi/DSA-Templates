#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);    
} 

void solve() {
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++) cin>>arr[i];
	
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) 
		solve();
	return 0;
}