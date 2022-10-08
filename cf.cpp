#include<bits/stdc++.h>
using namespace std;

int solve(int n, int a, int b, int c,vector<int>&arr) {
	if(n==0) {
		return 0;
	}
	if(n<0) return -4000;

	if(arr[n]!=-1) return arr[n]; 
	int x = 1 + solve(n-a,a,b,c,arr);
	int y = 1 + solve(n-b,a,b,c,arr);
	int z = 1 + solve(n-c,a,b,c,arr);
	return arr[n] = max({x,y,z});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int t;
	// cin>>t;
	// vector<int> a;
	// while(t--) {
		int n;
		cin>>n;
		int a,b,c;
		cin>>a>>b>>c;
		vector<int> arr(n+2,-1);
		cout<<solve(n,a,b,c,arr);
	// }
	return 0;
}