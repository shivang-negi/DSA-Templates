#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:    
    int knapSack(int W, int wt[], int val[], int n)  { 
        //  if(W==0 || n==0) return 0;
        //  else if(W-wt[n-1]<0) return knapSack(W, wt, val, n - 1);
        //  else
        //     return max(val[n-1] + knapSack(W-wt[n-1],wt,val,n-1), knapSack(W,wt,val,n-1));
        int dp[n+1][W+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=W;j++) {
                if(j<wt[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],dp[i-1][j]);  
            }
        }
        return dp[n][W];
    }
};

//Max Optimized
int KnapSack(int val[], int wt[], int n, int W) {
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 0; i < n; i++)
        for (int j = W; j >= wt[i]; j--)
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
            
    return dp[W];
}

int main() {
    Solution obj;
    int wt[4] = {1,2,3,4};
    int val[4] = {2,4,4,5};
    cout<<obj.knapSack(7,wt,val,4);
    return 0;
}
