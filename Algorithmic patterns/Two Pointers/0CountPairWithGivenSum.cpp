#include<bits/stdc++.h>
using namespace std;

//count of array pairs with given target sum

int getPairsCount(int arr[], int n, int target) {
    unordered_map<int,int> hash;
    int c = 0;
    for(int i=0;i<n;i++) {
        int x = arr[i];
        if(hash.find(target-x)!=hash.end()) c+=hash[target-x];
        hash[x]++;
    }
    return c;
}

int main() {
    int arr[4] = {1,1,1,1};
    cout<<getPairsCount(arr,4,2);
    return 0;
}

//using Two Pointer with sorting, time complexity - O(nlogn)
    // int left=0;
    // int right=n-1;
    // int count=0;      
    
    // sort(arr,arr+n); 
    
    // while(left<=right){
    //     if(arr[left]+arr[right] == k){
    //         count++;
    //     }
    //     else if(arr[left]+arr[right]>k){
    //         right--;
    //     }
    //     else{
    //         left++;
    //     }
    // }
    // return count;