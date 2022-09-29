#include<bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int K, int arr[], int N){
    long mx=INT_MIN, sum = 0;
    for(int i=0;i<K;i++) {
        sum+=arr[i];
    }
    mx = max(sum,mx);
    for(int i=K;i<N;i++) {
        sum-=arr[i-K];
        sum+=arr[i];
        mx = max(sum,mx);
    }
    return mx;
}

int main() {
    int arr[5] = {4,5,6,7,8};
    cout<<maximumSumSubarray(3,arr,5);
    return 0;
}