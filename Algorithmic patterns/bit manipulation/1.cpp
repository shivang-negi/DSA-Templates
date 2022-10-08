#include<bits/stdc++.h>
using namespace std;

/*
Given two positive integers num1 and num2, find the integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x.


Input: num1 = 3, num2 = 5
Output: 3
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.

Input: num1 = 1, num2 = 12
Output: 3
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
*/

int bit_count(int n) {
    int c = 0;
    while(n) {
        c++;
        n = n & (n-1);
    }
    return c;
}

int get_bit(int num, int n) {
    return (1 & (num>>n));
}

int set_bit(int n, int k) {
    return (n | (1<<k));
}

int clear_bit(int n, int k) {
    return (n & (~(1<<k)));
}

int solve(int num1, int num2) {
    int cnt2 = bit_count(num2);
    int ans = 0;
    
    for(int i = 31 ; i >= 0 ; i--){
        if(get_bit(num1,i)==1){
            ans = set_bit(ans,i);
            cnt2--;
            if(cnt2 == 0) break;
        }
    }
    
    if(cnt2 > 0){
        for(int i = 0 ; i < 32 ; i++){
            if(get_bit(num1,i)==0){
                ans = set_bit(ans,i);
                cnt2--;
                if(cnt2 == 0) break;
            }
        }
    }
    
    return ans;
}

int main() {
    cout<<solve(12,789);
    return 0;
}