#include<iostream>
using namespace std;

void lengthOfLongestSubstring(string s) {
    int count[256] = {0};
    int l = 0;
    int r = 0;
    int st=0, end=0;
    int ans = 0;
    while(r<s.length()){
        count[s[r]]++;
        while(count[s[r]]>1){
            count[s[l]]--;
            l++;
        }
        if(r-l+1>ans) {
            ans = r-l+1;
            st = l;
            end = r;
        }
        r++;
    }
    cout<<"Length of longest non-repeating substring: "<<ans<<endl;
    cout<<"Longest non-repeating substring: "<<s.substr(st,end-st+1);
}


int main() {
    lengthOfLongestSubstring("abcdddefggijklmnopppqes");
    return 0;
}