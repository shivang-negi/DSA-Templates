#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        unordered_map<int, int> hash;
        int n;
        cin>>n;
		int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n);
		int c = 0, mx = 0, mat = arr[0];
		for(int i=1;i<n;i++) {
			if(arr[i]==mat) c++;
			else {
				mat = arr[i];
				c = 0;
			}
			mx = max(mx, c);
		}
		cout<<mx<<endl;
    }
    return 0;
}