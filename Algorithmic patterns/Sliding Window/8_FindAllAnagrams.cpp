#include<bits/stdc++.h>
using namespace std;

/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word 
or phrase, typically using all the original letters exactly once.

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
*/

vector<int> findAnagrams(string s, string p) {
    vector <int> res;
    int n1=s.size(),n2=p.size();
    int c=0;
    if(n2>n1) return res;
    
    int i,count[26] = {0};
    
    for(int i=0;i<n2;i++) {
        count[s[i]-'a']++;
        count[p[i]-'a']--;
    }
    
    for( i=n2;i<n1;i++) {
        bool x=false;
        for(int j=0;j<26;j++) {
            if(count[j]!=0) x=true;
        }
        if(!x) res.push_back(i-n2);
        
        count[s[i-n2]-'a']--;
        count[s[i]-'a']++;
    }
    bool x=false;
    for(int j=0;j<26;j++) {
        if(count[j]!=0) x=true;
    }
    if(!x) res.push_back(i-n2);
    return res;
}

int main() {
    vector<int> x = findAnagrams("abc","cab");
    for(int a: x) cout<<a<<endl;
    return 0;
}

//OPTIMIZED:

vector<int> find(string s, string p) {
    int letters[26] = {0};
    for(char c : p) letters[c - 'a']++;
    
    vector<int> result;
    int remaining = p.size(), j = 0;
    for(int i = 0; i< s.size(); i++){
        while(j < s.size() && j - i < p.size()){
            if(letters[s.at(j++) - 'a']-- > 0)
                remaining--;
        }
        if(remaining == 0 && j - i == p.size()) 
            result.push_back(i);
        if(letters[s.at(i) - 'a']++ >= 0) 
            remaining++;            
    }
    return result;
}