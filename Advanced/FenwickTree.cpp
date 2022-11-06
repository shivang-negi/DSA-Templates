#include<bits/stdc++.h>
using namespace std;

vector<int> bit;

void updateUtil(int n,int ind, int delta){
    ind++;
    while(ind<=n) {
        bit[ind]+=delta;
        ind+=(ind&-ind);
    }
}

void buildBIT(vector<int> &arr, int n){ 
    bit.resize(n+1,0);
    for(int i=0;i<n;i++)
        updateUtil(n, i, arr[i]);
}

void update(vector<int> &arr, int n, int ind, int val) {
    int delta=val-arr[ind];
    arr[ind]=val;
    updateUtil(n, ind, delta);
}

// Function to find the sum of array 
//  elements in the range [0, ind].
int findSum(int ind){
    int sum=0;
    while(ind>0){
        sum+=bit[ind];
        ind-=(ind&(-ind));
    }
    return sum;
}

int sumRange(int left, int right) {
    return findSum(right+1)-(findSum(left));
}

int main() {
    // vector<int> arr({1,2,4,5,6});
    // int n = 5;
    // buildBIT(arr,n);
    // cout<<sumRange(0,n-1)<<" ";
    // cout<<sumRange(2,4)<<" ";
    // cout<<sumRange(1,3)<<" ";
    // update(arr,n,4,0);
    // cout<<sumRange(0,n-1)<<" ";
    // cout<<sumRange(4,4)<<" ";

    // cout<<"\n";

    vector<int> t({1,3,5});
    int n = 3;
    buildBIT(t,n);
    cout<<sumRange(0,2)<<" ";
    update(t,n,1,2);
    cout<<sumRange(0,2)<<" ";
    return 0;
}