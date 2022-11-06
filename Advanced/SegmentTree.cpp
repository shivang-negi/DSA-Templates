#include<bits/stdc++.h>
using namespace std;

vector<int> tree;

inline int merge(int a, int b) {    //To get range sum
    return a+b;                     //For max, use max(a,b) 
}

void buildSegTree(vector<int>& arr, int treeIndex, int lo, int hi) {
    if (lo == hi) {  // leaf node
        tree[treeIndex] = arr[lo];
        return;
    }
    int mid = lo + (hi - lo) / 2;  
    buildSegTree(arr, 2 * treeIndex + 1, lo, mid);
    buildSegTree(arr, 2 * treeIndex + 2, mid + 1, hi);
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
}

int querySegTree(int treeIndex, int lo, int hi, int i, int j) {
    // query for arr[i..j]

    if (lo > j || hi < i) return 0;     // If segment completely outside range
    
    if (i <= lo && j >= hi) return tree[treeIndex]; // If segment completely inside range

    int mid = lo + (hi - lo) / 2;       // partial overlap of current segment

    if (i > mid) return querySegTree(2 * treeIndex + 2, mid + 1, hi, i, j);
    else if (j <= mid) return querySegTree(2 * treeIndex + 1, lo, mid, i, j);

    int leftQuery = querySegTree(2 * treeIndex + 1, lo, mid, i, mid);
    int rightQuery = querySegTree(2 * treeIndex + 2, mid + 1, hi, mid + 1, j);
    return merge(leftQuery, rightQuery);
}

void updateValSegTree(int treeIndex, int lo, int hi, int arrIndex, int val) {
    if (lo == hi) {                 // leaf node. update element.
        tree[treeIndex] = val;
        return;
    }

    int mid = lo + (hi - lo) / 2;   // recurse deeper for appropriate child

    if (arrIndex > mid)
        updateValSegTree(2 * treeIndex + 2, mid + 1, hi, arrIndex, val);
    else if (arrIndex <= mid)
        updateValSegTree(2 * treeIndex + 1, lo, mid, arrIndex, val);

    // merge updates
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
}

int main() {
    int n = 6;
    vector<int> arr({7,4,3,6,1,4});
    tree.resize(4*n);
    buildSegTree(arr,0,0,n-1);
    for(int x: tree) cout<<x<<" ";
    cout<<endl;
    cout<<querySegTree(0,0,n-1,2,4)<<" ";
    updateValSegTree(0,0,n-1,3,8);
    cout<<querySegTree(0,0,n-1,1,4)<<" ";
    cout<<querySegTree(0,0,n-1,0,3)<<" ";
    cout<<querySegTree(0,0,n-1,4,5);
    return 0;
}