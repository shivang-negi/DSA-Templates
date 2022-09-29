#include<iostream>
#include<vector>
using namespace std;

void find_subset(vector<int>&arr,vector<vector<int>> &res, int ind, vector<int> temp, int n) {
    res.push_back(temp);
    for(int i=ind;i<n;i++) {
        temp.push_back(arr[i]);
        find_subset(arr,res,i+1,temp,n);
        temp.pop_back();
    }    
}

int main() {
    vector<int> arr({1,2,3,4});
    vector<vector<int>> res;
    find_subset(arr,res,0,{},arr.size());
    for(int i=0;i<res.size();i++) {
        cout<<"{";
        for(int x: res[i]) {
            cout<<x<<" ";
        }
        cout<<"}"<<endl;
    }
    return 0;
}