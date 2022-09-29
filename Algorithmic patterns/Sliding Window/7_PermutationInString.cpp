#include<bits/stdc++.h>
using namespace std;

/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false
otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/

bool check(int count[26])
{
    for(int i=0;i<26;i++) 
        if(count[i]!=0)
            return false;
    return true;
}
bool checkInclusion(string s1, string s2) {
    
    int m = s1.size();
    int n = s2.size();
    int i;
    
    if(m>n) return false;
    
    int count[26] = {0};
    
    for(i=0;i<m;i++) {
        count[s1[i]-'a']++;
        count[s2[i]-'a']--;
    }
    if(check(count)) return true;
    
    for(i=m;i<n;i++)
    {
        count[s2[i]-'a']--;
        count[s2[i-m]-'a']++;
        if(check(count)) return true;
    }
    return false;
}

int main() {
    cout<<checkInclusion("ab","eidbaooo");
    return 0;
}

//OPTIMIZED:

bool check(string s1, string s2) {
    int k = s1.size();
    int n = s2.size();
    int map[26] = {0};
    for(char c : s1) map[c - 'a']++;
    int j = 0, i = 0, count_chars = k;
    while(j < n) {
        if(map[s2[j++] - 'a']-- > 0) count_chars--;
        if(count_chars == 0) return true;
        if(j - i == k && map[s2[i++]-'a']++ >= 0) count_chars++;
    }
    return false;
}