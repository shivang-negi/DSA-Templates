#include<bits/stdc++.h>
using namespace std;

/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's
in the array if you can flip at most k 0's.

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
*/

int longestOnes(vector<int> nums, int k) {
    int n = nums.size();
    int zero = 0;
    int l = 0, r = 0;
    int mx = 0;
    while(r<n) {
        if(nums[r]==0) zero++;
        while(zero>k) {
            if(nums[l]==0) zero--;
            l++;
        }
        mx = max(mx,r-l+1);
        r++;
    }
    return mx;
}

int main() {
    cout<<longestOnes({1,1,1,0,0,0,1,1,1,1,0},2);
    return 0;
}