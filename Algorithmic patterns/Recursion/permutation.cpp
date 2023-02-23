#include<iostream>
#include<vector>
using namespace std;

void permute(vector<int>&num, int begin,vector<vector<int>>&result) {
    if (begin >= num.size()) {
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permute(num, begin + 1, result);
		    swap(num[begin], num[i]);
		}
}

int main() {
    vector<int> arr({1,2,3,4});
    vector<vector<int>> res;
    permute(arr,0,res);
    for(int i=0;i<res.size();i++) {
        cout<<"{";
        for(int x: res[i]) {
            cout<<x<<" ";
        }
        cout<<"}"<<endl;
    }
}