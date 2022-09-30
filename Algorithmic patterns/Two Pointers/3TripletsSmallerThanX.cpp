#include<bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of distinct integers of size N and a value sum, the task is to 
find the count of triplets (i, j, k), having (i<j<k) with the sum of 
(arr[i] + arr[j] + arr[k]) smaller than the given value sum.

Input: N = 4, sum = 2
arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3). 
*/

int countTriplets(int arr[], int n, int k) {
    int c = 0;
    sort(arr,arr+n);
    for(int i=0;i<n;i++) {
        int front = i + 1;
        int back = n-1;
        while(front<back) {
            long long sum = arr[i] + arr[front] + arr[back];
            if(sum<k) {
                c+=(back-front);
                front++;
            }
            else back--;
        }
    }
    return c;
}

int main() {
    return 0;
}