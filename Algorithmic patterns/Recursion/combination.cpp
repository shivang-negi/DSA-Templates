#include<iostream>
#include<vector>
using namespace std;

void helper(int n,int k, int ind,vector<int> &arr,vector<vector<int>>&res,vector<int>temp) {
    if(temp.size()==k) {
        res.push_back(temp);
        return;
    }
        
    for(int i=ind;i<n;i++) {
        temp.push_back(arr[i]);
        helper(n,k,i+1,arr,res,temp);
        temp.pop_back();
    }
}

int main() {
    vector<int> arr({1,2,3,4});
    vector<vector<int>> res;
    helper(arr.size(),2,0,arr,res,{});
    for(int i=0;i<res.size();i++) {
        cout<<"{";
        for(int x: res[i]) {
            cout<<x<<" ";
        }
        cout<<"}"<<endl;
    }
}