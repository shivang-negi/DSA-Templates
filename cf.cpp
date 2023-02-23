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
	ll n,k;
	cin>>n>>k;
	
	vector<pair<ll,ll>> arr(n,{0,0});
	for(ll i=0;i<n;i++) cin>>arr[i].first;
	for(ll i=0;i<n;i++) cin>>arr[i].second;

	sort(arr.begin(),arr.end(),[](pair<ll,ll>&x, pair<ll,ll>&y) {
		if((x.first + x.second) == (y.first + y.second)) {
			return x.second < y.second;
		}
		return (x.first + x.second) < (y.first + y.second); 
	});

	ll ans = 0, cur = 0;
	for(ll i=0;i<n;i++) {
		if((cur+arr[i].first) > k) {
			ll mn = arr[i].first;
			for(ll j=i;j<n;j++) mn = min(mn,arr[j].first);
			if((cur+mn)<=k) ans++;
			break;
		}
		cur+=(arr[i].first+arr[i].second);
		ans++;
	}
	cout<<ans<<"\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r", stdin);
		freopen("output.txt","w",stdout);
    #endif
	// #ifndef ONLINE_JUDGE
	// freopen("circlecross.in" ,"r", stdin);
	// freopen("circlecross.out","w",stdout);
	// #endif
	int t;cin>>t;while(t--)
		solve();
	return 0;
}