#include<bits/stdc++.h>
using namespace std;

/*
You are given a string s and an integer k. You can choose any character of the string 
and change it to any other uppercase English character. You can perform this operation 
at most k times.
Return the length of the longest substring containing the same letter you can get after 
performing the above operations.

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/

int characterReplacement(string s, int k) {
    int n = s.size();
    int count[26] = {0};
    int start = 0, res = 0;
    int max_char=0;
    for(int r=0;r<n;r++) {
        count[s[r]-'A']++;
        max_char = max(max_char,count[s[r]-'A']);
        while(r-start+1-max_char>k) {//Length of substring - Maximum occuring character
            count[s[start]-'A']--;
            start++;
        }
        res = max(res,r-start+1);
    }
    return res;
}

int main() {
    cout<<characterReplacement("AABABBA",1);
    return 0;
}