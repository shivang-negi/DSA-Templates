#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>& cd, int target,vector<int> temp,int ind,int n,vector<vector<int>>&res) {
    if(target==0) {
        res.push_back(temp);
        return;
    }
        
    if(target<0) return;
        
    for(int i=ind;i<n;i++) {
        temp.push_back(cd[i]);
        helper(cd,target-cd[i],temp,i,n,res);
        temp.pop_back();
    }
}

int main() {
    vector<int> arr({2,3,6,7});
    vector<vector<int>> res;
    helper(arr,7,{},0,arr.size(),res);
    for(int i=0;i<res.size();i++) {
        cout<<"{";
        for(int x: res[i]) {
            cout<<x<<" ";
        }
        cout<<"}"<<endl;
    }
    return 0;
}