#include<bits/stdc++.h>
using namespace std;

//Lazy propogation is used when we perform update on a range
//For sum of a range, update increments value of a range by "val"

vector<int> seg,lazy;

void build(vector<int>& arr, int treeIndex, int lo, int hi) {
    if (lo == hi) {  
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
    if (lazy[treeIndex] != 0) {          
        seg[treeIndex]+=(hi-lo+1)*lazy[treeIndex]; 

        if (lo != hi) {        
            lazy[2 * treeIndex + 1] += lazy[treeIndex];
            lazy[2 * treeIndex + 2] += lazy[treeIndex];
        }

        lazy[treeIndex] = 0;       
    }

    if (lo > hi || lo > j || hi < i)
        return;                  

    if (i <= lo && hi <= j) {             
        seg[treeIndex] += (hi - lo + 1) * val;   

        if (lo != hi) {                  
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
    if (lo > j || hi < i)     
        return 0;     

    if (lazy[treeIndex] != 0) {                             
        seg[treeIndex] += (hi - lo + 1) * lazy[treeIndex]; 

        if (lo != hi) {                                    
            lazy[2 * treeIndex + 1] += lazy[treeIndex];
            lazy[2 * treeIndex + 2] += lazy[treeIndex];
        }

        lazy[treeIndex] = 0;                             
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

    return leftQuery + rightQuery;
}
// call this method as queryLazySegTree(0, 0, n-1, i, j);
// Here [i,j] is the range/interval you are querying.
// This method relies on "null" nodes being equivalent to storing zero.

int main() {
    int n = 5;
    vector<int> arr({1,1,1,1,1});
    seg.resize(4*n,0);
    lazy.resize(4*n,0);

    build(arr,0,0,n-1);
    // for(int x: seg) cout<<x<<" ";cout<<"\n";
    cout<<query(0,0,n-1,0,n-1)<<" ";

    update(0,0,2,0,n-1,1);
    cout<<query(0,0,n-1,0,n-1)<<" ";

    return 0;
}

struct SegMenTree
{
    vector<int> segtree;
    vector<bool> lazy;
    int n;
 
    void init(int _n)
    {
        n=1;
        while(n<_n)
            n=n*2;
        segtree.resize(2*n,0);
        lazy.resize(2*n,false);
    }
 
    void pUpdate(int node,int l,int r,int index,int val)
    {
        if(r-l==1)
        {
            segtree[node]=val;
            return;
        }
 
        int mid=(l+r)/2;
        if(index<mid)
            pUpdate(2*node+1,l,mid,index,val);
        else
            pUpdate(2*node+2,mid,r,index,val);
 
        segtree[node]=segtree[2*node+1]+segtree[2*node+2];
    }
 
    void propagate(int node,int l,int r)
    {
        if(!lazy[node])
            return;
 
        if(r-l==1)
        {
            segtree[node]=1-segtree[node];
        }
        else {
            segtree[node]=(r-l)-segtree[node];
            lazy[2*node+1]=!lazy[2*node+1];
            lazy[2*node+2]=!lazy[2*node+2];//this is a specific case like yaha par 2 operations means segment remains
            //same so we are doing this warna woh true wala hi rehta
        }
        lazy[node]=false;
    }
 
    void rupdate(int node,int l,int r,int i,int j)
    {
        propagate(node,l,r);
 
        if(r<=i || j<=l)
            return;
        if(i<=l && r<=j)
        {
            lazy[node]=1;
            propagate(node,l,r);
            return;
        }
 
        int mid=(l+r)/2;
        rupdate(2*node+1,l,mid,i,j);
        rupdate(2*node+2,mid,r,i,j);
 
        segtree[node]=segtree[2*node+1]+segtree[2*node+2];
    }
 
    int query(int node,int l,int r,int i,int j)
    {
        propagate(node,l,r);
 
        if(r<=i || j<=l)
            return 0;
        if(i<=l && r<=j)
            return segtree[node];
 
        int mid=(l+r)/2;
        return query(2*node+1,l,mid,i,j)+query(2*node+2,mid,r,i,j);
    }
};

vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
    int n=nums1.size();
    SegMenTree st;
    st.init(n);
    int sz=st.n;
    for(int i=0;i<n;i++)
        st.pUpdate(0,0,sz,i,nums1[i]);
    
    long long ans=0ll;
    for(auto ele : nums2)
        ans=ans+ele*1ll;
    
    vector<long long> output;
    for(auto query : queries)
    {
        int type=query[0];
        if(type==1)
        {
            int l=query[1];
            int r=query[2];
            st.rupdate(0,0,sz,l,r+1);
        }
        else if(type==2)
        {
            long long p=query[1];
            long long sum=st.query(0,0,sz,0,n+1);
            ans=ans+sum*p;
        }
        else
            output.push_back(ans);
    }
    return output;
}