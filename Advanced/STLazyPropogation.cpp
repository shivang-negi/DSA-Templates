#include<bits/stdc++.h>
using namespace std;

//Lazy propogation is used when we perform update on a range
//For sum of a range, update increments value of a range by "val"

vector<int> seg,lazy;

void build(vector<int>& arr, int treeIndex, int lo, int hi) {
    if (lo == hi) {  // leaf node
        seg[treeIndex] = arr[lo];
        return;
    }
    int mid = lo + (hi - lo) / 2;  
    build(arr, 2 * treeIndex + 1, lo, mid);
    build(arr, 2 * treeIndex + 2, mid + 1, hi);
    seg[treeIndex] = (seg[2 * treeIndex + 1]  + seg[2 * treeIndex + 2]);
}

void update(int treeIndex, int lo, int hi, int i, int j, int val)
{
    if (lazy[treeIndex] != 0) {           // this node is lazy
        seg[treeIndex]+=(hi-lo+1)*lazy[treeIndex]; //normalize node by removing laziness

        if (lo != hi) {         // update lazy[] for children nodes
            lazy[2 * treeIndex + 1] += lazy[treeIndex];
            lazy[2 * treeIndex + 2] += lazy[treeIndex];
        }

        lazy[treeIndex] = 0;         // current node processed. No longer lazy
    }

    if (lo > hi || lo > j || hi < i)
        return;                   // out of range. escape.

    if (i <= lo && hi <= j) {              // segment is fully within update range
        seg[treeIndex] += (hi - lo + 1) * val;      // update segment

        if (lo != hi) {                     // update lazy[] for children
            lazy[2 * treeIndex + 1] += val;
            lazy[2 * treeIndex + 2] += val;
        }
        return;
    }

    int mid = lo + (hi - lo) / 2;

    update(2 * treeIndex + 1, lo, mid, i, j, val);
    update(2 * treeIndex + 2, mid + 1, hi, i, j, val);

    seg[treeIndex] = seg[2 * treeIndex + 1] + seg[2 * treeIndex + 2]; //merge
}
// call this method as updateLazySegTree(0, 0, n-1, i, j, val);
// Here you want to update the range [i, j] with value val.

int query(int treeIndex, int lo, int hi, int i, int j)
{
    // query for arr[i..j]
    if (lo > j || hi < i)        //If segment completely outside range, return 0
        return 0;     

    if (lazy[treeIndex] != 0) {                             // this node is lazy
        seg[treeIndex] += (hi - lo + 1) * lazy[treeIndex]; // normalize current node by removing laziness

        if (lo != hi) {                                     // update lazy[] for children nodes
            lazy[2 * treeIndex + 1] += lazy[treeIndex];
            lazy[2 * treeIndex + 2] += lazy[treeIndex];
        }

        lazy[treeIndex] = 0;                                // current node processed. No longer lazy
    }

    if (i <= lo && j >= hi)                                 // segment completely inside range
        return seg[treeIndex];

    int mid = lo + (hi - lo) / 2;                           // partial overlap of current segment and queried range. Recurse deeper.

    if (i > mid)
        return query(2 * treeIndex + 2, mid + 1, hi, i, j);
    else if (j <= mid)
        return query(2 * treeIndex + 1, lo, mid, i, j);

    int leftQuery = query(2 * treeIndex + 1, lo, mid, i, mid);
    int rightQuery = query(2 * treeIndex + 2, mid + 1, hi, mid + 1, j);

    // merge query results
    return leftQuery + rightQuery;
}
// call this method as queryLazySegTree(0, 0, n-1, i, j);
// Here [i,j] is the range/interval you are querying.
// This method relies on "null" nodes being equivalent to storing zero.

int main() {
    int n = 5;
    vector<int> arr({1,2,3,4,5});
    seg.resize(4*n,0);
    lazy.resize(4*n,0);

    build(arr,0,0,n-1);
    for(int x: seg) cout<<x<<" ";cout<<"\n";
    cout<<query(0,0,n-1,0,n-1)<<" ";
    cout<<query(0,0,n-1,3,n-1)<<" ";
    cout<<query(0,0,n-1,2,2)<<" ";

    update(0,0,n-1,0,n-1,1);
    cout<<query(0,0,n-1,0,n-1)<<" ";

    return 0;
}