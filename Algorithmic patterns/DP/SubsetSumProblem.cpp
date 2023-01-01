#include<bits/stdc++.h>
using namespace std;

// Equal sum partition
bool helper(vector<int>&nums , int sum, int ind, vector<vector<int>>&memo) {
    if(sum==0) return true;
    else if(ind<0) return false;
    if(memo[ind][sum]!=-1) return memo[ind][sum];
    else if(nums[ind]>sum) return memo[ind][sum] = helper(nums,sum,ind-1,memo);
    else
        return memo[ind][sum] = helper(nums,sum,ind-1,memo) || helper(nums,sum-nums[ind],ind-1,memo); 
}

// Equal sum partition
bool canPartition(vector<int> nums) {
    int sum = 0;
    for(int x:nums)
        sum+=x;
                                                
    if(sum & 1) return false;
    
    sum/=2;
    int n = nums.size();
    
    bool dp[n+1][sum+1];
    
    dp[0][0] = true;
    
    for(int i = 1; i <= n; i++) dp[i][0] = true;
    for(int j = 1; j <= sum; j++) dp[0][j] = false;
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=sum;j++) {
            if(j<nums[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
        }
    }
    return dp[n][sum];
}

// Count of Subset with given sum
bool canPartition(vector<int> nums, int sum) {
    
    int n = nums.size();
    
    int dp[n+1][sum+1];
    
    dp[0][0] = 1;
    
    for (int i = 1; i < n+1; i++) {
        dp[i][0] = 1;
    }
    for (int j = 1; j < sum+1; j++) {
        dp[0][j] = 0;
    }
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=sum;j++) {
            if(j<nums[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
        }
    }
    return dp[n][sum];
}

//Minimum Subset difference
int partition(vector<int>& stones) {
    int n = stones.size();
    int sum=0 , t;
    for(int x: stones) sum+=x;
    t = sum;
    sum = (sum/2);

    bool dp[n+1][sum+1];
    dp[0][0] = true;

    for(int i=1;i<=sum;i++) dp[0][i] = false;
    for(int i=1;i<=n;i++) dp[i][0] = true;
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=sum;j++) {
            if(stones[i-1]>j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i-1]];
        }
    }

    int res = 0;
    for(int i=1;i<=(sum/2);i++) 
        if(dp[n][i]) res = i; 
    
    return (t - (2*res));
}

int main() {
    cout<<canPartition({1,5,11,5});
    return 0;
}