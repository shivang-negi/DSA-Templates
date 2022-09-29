#include<bits/stdc++.h>
using namespace std;

/*
You are given a string s and an array of strings words. All the strings of words are of 
the same length.
A concatenated substring in s is a substring that contains all the strings of any 
permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", 
"efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated 
substring because it is not the concatenation of any permutation of words.

Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring
has to be of length 6.
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which 
is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which 
is a permutation of words.
*/

vector<int> findSubstring(string s, vector<string> words) {
    int n = s.size(), total = words.size(), len = words[0].size(); 
    vector<int> answer;

    unordered_map<string, int> freq;
    for(auto w: words)
        freq[w]++;

    for(int i = 0; i < n - total * len + 1; i++) {
        int j = i;
        unordered_map<string, int> stats = freq;
        int covered = 0;
        while(covered < total && j + len - 1 < n) {
            string word = s.substr(j, len);
            if(stats.find(word) != stats.end() && --stats[word] >= 0) { 
                covered++;
                j += len;
            }
            else break;
        }
        if(covered == total) answer.push_back(i);
    }
    return answer;
}

int main() {
    vector<int> arr = findSubstring("barfoothefoobarman",{"foo","bar"});
    for(int x: arr) cout<<x<<" ";
    return 0;
}