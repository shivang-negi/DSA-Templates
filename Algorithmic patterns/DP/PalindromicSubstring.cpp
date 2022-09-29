#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int i=n-1;i>=0;i--) { //DP
            for(int j=i;j<n;j++) {
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1]))
                    dp[i][j] = 1;
            }
        }
        string str = "";
        int start = 0, len = 0;
        for(int i=0;i<n;i++) {  //Longest palindrome substring
            for(int j=0;j<n;j++) {
                if(dp[i][j] && (j-i+1)>len) {
                    start = j;
                    len = j-i+1;
                }
            }
        }
        str = s.substr(start-len+1,len);
        return str;
    }
};