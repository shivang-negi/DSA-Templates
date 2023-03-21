#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long mod = 1e9 + 7;
inline void no() { cout << "NO\n"; }
inline void yes() { cout << "YES\n"; }
inline void dbg() { cout << "here\n"; }
inline long long get_bit(long long num, long long n) { return (1 & (num >> n)); }
inline long long set_bit(long long n, long long k) { return (n | (1 << k)); }
inline long long clear_bit(long long n, long long k) { return (n & (~(1 << k))); }
long long lcm(long long a, long long b) { return a / __gcd(a, b) * b; }

bool collinear(int x1, int y1, int x2,
               int y2, int x3, int y3) {
    
    int a = x1 * (y2 - y3) +
            x2 * (y3 - y1) +
            x3 * (y1 - y2);
 
    return (a == 0);
}

void solve() {
	int n,m;
	cin>>n>>m;
	int x,y, tx, ty;
	cin>>x>>y>>tx>>ty;
	string dir;
	cin>>dir;

	set<pair<int,int>> s;
	s.insert({x,y});
	int curx, cury;

	int c = 0;
	while(true) {
		int nx = x, ny = y;
		if(dir=="DL") {
			int disl = y - 1;
			int disd = n - x;

			int m = min(disl,disd);
			x+=m;
			y-=m;

			if(x==n && y==1) dir = "UR";
			else if(x==n) dir = "UL";
			else dir = "DR";
		}
		else if(dir == "UL") {
			int disl = y - 1;
			int disu = x - 1;
			int m = min(disl,disu);
			x-=m;
			y-=m;

			if(x==1 && y==1) dir = "DR";
			else if(x==1) dir = "DL";
			else dir = "UR";
		}
		else if(dir=="UR") {
			int disr = m - y;
			int disu = x - 1;
			int m = min(disr,disu);
			x-=m;
			y+=m;

			if(x==1 && y==m) dir = "DL";
			else if(x==1) dir = "DR";
			else dir = "UL";
		}
		else {
			int disr = m - y;
			int disd = n - x;
			int m = min(disr,disd);
			x+=m;
			y+=m;

			if(x==n && y==m) dir = "UL";
			else if(x==n) dir = "UR";
			else dir = "DL";
		}
		cout<<x<<" "<<y<<"\n";
		if(s.count({x,y})) break;
		if(collinear(nx,ny,x,y,tx,ty)) {
			cout<<c<<"\n";
			return;
		}
		c++;
	}
	cout<<"-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	// freopen("angry.in" ,"r", stdin);
	// freopen("angry.out","w",stdout);
	int t;cin>>t;while(t--)
	solve();
	return 0;
}