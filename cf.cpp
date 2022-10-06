#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		long long ans = 0;
		if(arr[0]==1) {
			for(int i=1;i<n;i++) ans+=(arr[i]-1);
		}
		else {
			double mn = (2*arr[0]) - 1;
			for(int i=0;i<n;i++) {
				if(arr[i]>mn) {
					double temp = arr[i]/mn;
					ans+=(ceil(temp)-1);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}