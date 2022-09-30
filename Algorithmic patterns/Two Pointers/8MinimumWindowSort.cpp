#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, you need to find one continuous subarray that if you only 
sort this subarray in ascending order, then the whole array will be sorted in 
ascending order.
Return the shortest such subarray and output its length.

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array
sorted in ascending order.
*/

//O(nlogn)
int findUnsortedSubarray(vector<int>& nums) {
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    int n = nums.size(), l = 0, r = n - 1;
    while (l < n && nums[l] == sorted[l]) l++;  
    while (r > l && nums[r] == sorted[r]) r--;  
    return r - l + 1;
}

//O(n) Two Pointers 
//No clue how this works (┛◉Д◉)┛彡┻━┻
int findUnsortedSubarray(vector<int>& nums) {

    int ans = 0;  
    int i = 0;
    int j = nums.size() - 1;

    int curr_max=INT_MAX;
    int curr_min=INT_MIN;
    
    // Initialize end to -1, if we have all sorted in ascending order, 
    // then end-start+1 = -1+0+1 = 0 
    int start=0,end=-1;
    
    while(j >= 0) {
        // Check if the "num[start]" is greater than the minimum element so far
        if(nums[i] >= curr_min) curr_min = nums[i];
        else end = i;

        // Check if the "num[end]" is less than the maximum element so far
        if(nums[j] <= curr_max) curr_max = nums[j];
        else start = j;

        ++i;
        --j;
    }
    return end - start + 1;
}

int main() {
    return 0;
}

// 2 1 4 3
/*

0 3:
2 > min
min = 2
3 < max
max = 3

1 2:
end = 1
start = 2

2 1:
min = 4
max = 1

3 0:

*/