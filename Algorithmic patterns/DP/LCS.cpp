#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    
    int longestCommonSubstring(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int dp[m+1][n+1];
        int result = 0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(text1[i-1]==text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    result = max(result,dp[i][j]);
                }
            }
        }
        return result;
    }

    string printLcs(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        string dp[m+1][n+1];
        
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                dp[i][j] = "";

        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + text1[i-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution obj;
    string str = obj.printLcs("abcdefghi","abtyiohi");
    cout<<str;
    return 0;
}


//     int helper(string &str1,string &str2,int m, int n,vector<vector<int>>& memo) {
//         if(m==0 || n==0)
//             return 0;
        
//         if(memo[m][n]!=-1) return memo[m][n];
//         if(str1[m-1]==str2[n-1])
//             return memo[m][n] = 1+helper(str1,str2,m-1,n-1,memo);
        
//         else
//             return memo[m][n] = max(helper(str1,str2,m-1,n,memo),helper(str1,str2,m,n-1,memo));
//     }
    