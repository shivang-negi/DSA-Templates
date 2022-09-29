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

//10 9 2 5 8
/*

1 1 1 1 1 
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 2 3
*/