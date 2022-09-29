#include<bits/stdc++.h>
using namespace std;

/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in 
the window. If there is no such substring, return the empty string "".

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/

string minWindow(string s, string t) {
    int map[128] = {0};
    for(auto c: t) map[c]++;
    
    int k=t.size(), begin=0, end=0, d=INT_MAX, head=0;
    
    while(end<s.size()){
        if(map[s[end]]>0) k--; 
        map[s[end]]--;
        end++;
        while(k==0){
            if(end-begin<d) { 
                d=end-begin;
                head=begin;
            }
            if(map[s[begin]]==0) k++;       //Only characters from string t will be zero
            map[s[begin]]++;                //Rest of the characters will be negative.
            begin++;
        }  
    }
    return d==INT_MAX? "":s.substr(head, d);
}

int main() {
    cout<<minWindow("xvbancytoer","abc");
    return 0;
}