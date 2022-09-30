#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums and an integer k, return the number of contiguous 
subarrays where the product of all the elements in the subarray is strictly less than k.

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
*/

//Doesn't work for negative values and zero / Sliding Window
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k<=1) return 0;
    int n = nums.size();
    int c = 0,l = 0, r = 0, pr = 1;
    while(r<n) {
        pr = pr * nums[r];
        while(pr>=k) {
            pr = pr/nums[l];
            l++;
        }
        c+=r-l+1;
        r++;
    }
    return c;
}

/*
Two pointers method with logarithm, Doesn't work with zero either

int numSubarrayProductLessThanK(int nums[],int n, int k) {
    if (k == 0) return 0;
    double logk = log(k);
    double prefix[n + 1];
    for (int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + log(nums[i]);
    }

    int ans = 0;
    for (int i = 0; i < n + 1 ; i++) {
        int lo = i + 1, hi = n + 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (prefix[mi] < prefix[i] + logk - 1e-9) lo = mi + 1;
            else hi = mi;
        }
        ans += lo - i - 1;
    }
    return ans;
}
*/

int main() {
    return 0;
}