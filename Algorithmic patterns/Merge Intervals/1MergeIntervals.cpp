#include<bits/stdc++.h>
using namespace std;

/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping 
intervals, and return an array of the non-overlapping intervals that cover all the 
intervals in the input.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

vector<vector<int>> merge(vector<vector<int>> intervals) {
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i=1;i<n;i++) {
        int cur_end = res.back()[1];
        int st = intervals[i][0];
        int end = intervals[i][1];
        if(st>cur_end)
            res.push_back(intervals[i]);
        else
            res.back()[1] = max(cur_end,end);
    }
    return res;
}

int main() {
    vector<vector<int>> arr = merge({{1,3},{2,6},{8,10},{12,15}});
    for(auto x: arr) {
        for(auto y: x) {
            cout<<y<<" ";
        }cout<<endl;
    }
    return 0;
}