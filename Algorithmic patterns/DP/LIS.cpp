#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=1;
                
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i]>nums[j]) {
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        return *max_element(dp,dp+n);
    }
};

//O(nlogn)
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e10;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l]) d[l] = a[i];
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}

//10 9 2 5 8
/*

1 1 1 1 1 
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 2 3
*/