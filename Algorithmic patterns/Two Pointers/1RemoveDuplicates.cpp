#include<bits/stdc++.h>
using namespace std;

/*Remove Duplicates from sorted array (Push them to the end)
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: nums = [0,1,2,3,4,_,_,_,_,_]    */

int removeDuplicates(vector<int>& nums) {
    int l=nums.size();
    if(l==1) return l;
    int i=0,c=0;
    while(i<l-1)
    {
        if(nums[i]!=nums[i+1])
            nums[c++]=nums[i];
        i++;
    }
    nums[c++]=nums[l-1];
    return c;   //Length of sorted first part of array
}

int main() {
    vector<int> arr({0,0,1,1,1,2,2,3,3,3,4});
    cout<<removeDuplicates(arr);
    return 0;
}
