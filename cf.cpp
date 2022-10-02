#include<bits/stdc++.h>
using namespace std;

bool isUnique(int x) {
	int arr[10] = {0};
	while(x) {
		arr[x%10]++;
		x = x/10;
	}
	for(int i=0;i<10;i++)
		if(arr[i]>1) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	cin>>n;
	n++;
	while(!isUnique(n)) n++;
	cout<<n;
	return 0;
}