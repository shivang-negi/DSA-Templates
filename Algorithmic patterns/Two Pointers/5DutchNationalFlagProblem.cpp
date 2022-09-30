#include<bits/stdc++.h>
using namespace std;

/*
Given an array nums filled with 0,1 and 2 of size n, sort them in-place. 

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

//Two pass
void sortColors(vector<int>& nums) {
    int zero=0,n=nums.size();
    for(int i=0;i<n;i++) {
        if(nums[i]==0) {
            swap(nums[i],nums[zero]);
            zero++;
        }
    }
    
    int one = zero - 1;
    for(int i=zero;i<n;i++) {
        if(nums[i]==1) {
            one++;
            swap(nums[i],nums[one]);
        }
    }
}

//One Pass Two pointer
void sortColors(vector<int>& nums) {
    int l = 0, mid = 0, h = nums.size() - 1;
    while (mid <= h)
        if (nums[mid] == 0)
            swap(nums[mid++], nums[l++]);
        else if (nums[mid] == 1)
            mid++;
        else 
            swap(nums[mid], nums[h--]);
}

int main() {
    return 0;
}

