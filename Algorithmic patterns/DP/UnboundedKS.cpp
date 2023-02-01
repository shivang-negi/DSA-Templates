#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int dp[n+1][W+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=W;j++) {
                if(j<wt[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]],dp[i-1][j]);  
            }
        }
        return dp[n][W];
    }

    //Max optimized
    int KnapSack(int val[], int wt[], int n, int W) {
        int dp[W + 1];
        memset(dp, 0, sizeof(dp));
    
       for(int i=0;i<n;i++) {
            for(int j=1;j<=x;j++) {
                if(j>=val[i])
                    dp[j] = max(dp[j],val[i] + dp[j-wt[i]]);
            }
        }

        return dp[W];
    }
};