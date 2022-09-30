#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums sorted in non-decreasing order, return an array of the 
squares of each number sorted in non-decreasing order.

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]                                          */

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int left = 0;
    int right = n - 1;

    for (int i=n-1;i>=0;i--) {
        int square;
        if(abs(nums[left])<abs(nums[right])) {
            square = nums[right];
            right--;
        }
        else {
            square=nums[left];
            left++;
        }
        result[i] = square * square;
    }
    return result;
}


int main() {
    return 0;
}