#include<bits/stdc++.h>
using namespace std;

/*
Given a string you need to print longest possible substring that has atmost K unique
characters.

Input: Str = “aabbcc”, k = 2
Output: 4
Explanation: Max substring can be any one from {“aabb” , “bbcc”}.

*/

int longestKSubstr(string s, int k) {
    unordered_map<char,int> mp;
    int i = 0;
    int j = 0;
    int ans = -1;
    
    while(j < s.length()){
        mp[s[j]]++;
        
        while(mp.size() > k){
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
            ++i;
        }
        ans = max(ans,(j-i) + 1); 
        j++;
    }
    return ans;
}

int main() {
    cout<<longestKSubstr("aabcdefff",3);
    return 0;
}