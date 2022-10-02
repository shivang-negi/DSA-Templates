#include<bits/stdc++.h>
using namespace std;

/*
You are playing a game involving a circular array of non-zero integers nums. 
Each nums[i] denotes the number of indices forward/backward you must move if you 
are located at index i:
If nums[i] is positive, move nums[i] steps forward, and
If nums[i] is negative, move nums[i] steps backward.
Since the array is circular, you may assume that moving forward from the last element 
puts you on the first element, and moving backwards from the first element puts you 
on the last element.

A cycle in the array consists of a sequence of indices seq of length k where:
Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
Every nums[seq[j]] is either all positive or all negative.
k > 1
Return true if there is a cycle in nums, or false otherwise.

Input: nums = [2,-1,1,2,2]
Output: true
Explanation: The graph shows how the indices are connected. White nodes are jumping 
forward, while red is jumping backward.
We can see the cycle 0 --> 2 --> 3 --> 0 --> ...
*/

//No clue how this works (┛◉Д◉)┛彡┻━┻
int getIndex(int i, vector<int> nums) {
    int n = nums.size();
    return i + nums[i] >= 0? (i + nums[i]) % n: n + ((i + nums[i]) % n);
}
bool circularArrayLoop(vector<int> nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            continue;
        }
        int j = i, k = getIndex(i, nums);
        while (nums[k] * nums[i] > 0 && nums[getIndex(k, nums)] * nums[i] > 0) {
            if (j == k) {
                // check for loop with only one element
                if (j == getIndex(j, nums)) {
                    break;
                }
                return true;
            }
            j = getIndex(j, nums);  //slow pointer
            k = getIndex(getIndex(k, nums), nums);  //fast pointer
        }
        j = i;
        int val = nums[i];
        while (nums[j] * val > 0) {
            int next = getIndex(j, nums);
            nums[j] = 0;
            j = next;
        }
    }
    return false;
}


int main() {
    return 0;
}