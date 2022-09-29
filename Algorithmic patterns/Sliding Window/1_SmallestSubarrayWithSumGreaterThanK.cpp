#include<bits/stdc++.h>
using namespace std;

/*

Given an array of positive integers nums and a positive integer target, 
return the minimal length of a contiguous subarray of which the sum is greater 
than or equal to target. If there is no such subarray, return 0 instead.

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

*/

int minSubArrayLen(int target, vector<int> nums) {
    int sum = 0;
    int n = nums.size();
    int r = 0;
    int l=0,min_len=n+1;
    for(int i=0;i<n;i++) {
        sum = sum + nums[i];
        r++;
        while(sum>=target) {
            min_len = min(min_len,r - l);
            sum = sum - nums[l++];
        }
    }
    return (min_len<=n)?min_len:0;
}

int main() {
    cout<<minSubArrayLen(7,{2,3,1,2,4,3});
    return 0;
}