#include <bits/stdc++.h>
using namespace std;
int arr[100];
int memo[100][100];
int getmaxscore(int arr[], int l, int r, int n)
{
	int mscore = 0;
	if(memo[l][r]!=-1) return memo[l][r];
	for (int i = l + 1; i < r; i++) {

		int cs = getmaxscore(arr, l, i, n) + getmaxscore(arr, i, r, n);
		if (l == 0 && r == n)
			cs = cs + arr[i];
		else
			cs = cs + (arr[l] * arr[r]);

		if (cs > mscore)
			mscore = cs;
	}
	return memo[l][r] = mscore;
}

int main() 
{
	int n;
	cin>>n;
	arr[0] = 1;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	arr[n+1] = 1;
	memset(memo,-1,sizeof(memo));
	cout << getmaxscore(arr, 0, n + 1, n + 1) << "\n";
    return 0;
}
