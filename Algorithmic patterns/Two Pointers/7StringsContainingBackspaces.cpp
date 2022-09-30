#include<bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, return true if they are equal when both are typed into 
empty text editors. '#' means a backspace character.

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b"
*/

//build and compare string
bool backspaceCompare(string s, string t) {
    string str1="",str2="";

    for(auto ch: s) {
        if(ch=='#' && !str1.empty()) str1.pop_back();
        else str1.push_back(ch);
    }

    for(auto ch: t) {
        if(ch=='#' && !str2.empty()) str2.pop_back();
        else str2.push_back(ch);
    }

    return str1==str2;
}

//Two Pointer
bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) { //While there may be chars in build(S) or build (T)
            while(i >= 0) { //Find position of next possible char in build(S)
                if (S[i] == '#') {skipS++; i--;}
                else if (skipS > 0) {skipS--; i--;}
                else break;
            }
            while(j >= 0) { //Find position of next possible char in build(T)
                if (T[j] == '#') {skipT++; j--;}
                else if (skipT > 0) {skipT--; j--;}
                else break;
            }
            //If two actual characters are different
            if (i >= 0 && j >= 0 && S[i] != T[j]) return false;
            //If expecting to compare char vs nothing
            if ((i >= 0) != (j >= 0)) return false;
            i--; j--;
        }
        return true;
    }

int main() {
    return 0;
}