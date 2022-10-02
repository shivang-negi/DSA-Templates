#include<bits/stdc++.h>
using namespace std;

/*
Given a number N find whether its a happy number or not. 
A number is called happy if it leads to 1 after a sequence of steps wherein each step, 
the number is replaced by the sum of squares of its digit that is if we start with Happy 
Number and keep replacing it with digits square sum, we reach 1.

Input: N = 19
Output: 1

Explanation:
19 is a Happy Number,
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
As we reached to 1, 
19 is a Happy Number.
*/

/*
Check for cycle
                                 145
                                /   \
                               89    42
                              /       \     
            116---38---73---58         20
                              \       /
                               37    4
                                \   /
                                  16
*/

//O(logn)
bool isHappy(int n) {
    long long int c=0;
    while(n>9) {
        c=0;
        int t=n;
        while(t>0) {
            int a=t%10;
            c=c+pow(a,2);
            t=t/10;
        }
        n=c;
    }
    if(n==1 || n==7)
        return true;
    else
        return false;
}

//Using fast and slow pointers
int next(int n) {
    int sum = 0;
    while(n != 0) {
        sum += pow(n % 10,2);
        n = n / 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = next(n);
    int fast = next(next(n));    
    while(slow != fast) {
        slow = next(slow);
        fast = next(next(fast));
    }
    return fast == 1 ;
}

int main() {
    return  0;
}