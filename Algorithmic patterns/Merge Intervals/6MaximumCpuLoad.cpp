#include<bits/stdc++.h>
using namespace std;

/*
Given an array of jobs with different time requirements, where each job consists of 
start time, end time and CPU load. The task is to find the maximum CPU load at any 
time if all jobs are running on the same machine.

Input: jobs[] = {{1, 4, 3}, {2, 5, 4}, {7, 9, 6}} 
Output: 7 
Explanation: 
In the above-given jobs, there are two jobs which overlaps. 
That is, Job [1, 4, 3] and [2, 5, 4] overlaps for the time period in [2, 4] 
Hence, the maximum CPU Load at this instant will be maximum (3 + 4 = 7).
*/

//Approach 1 Time O(NlogN) and Space O(n)
struct endCompare {
    bool operator()(const vector<int>& x, const vector<int>& y)
    {
        return x[1] > y[1]; //sorting according to end time
    }
};

int max_load(vector<vector<int>> arr) {
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int maxCPULoad = 0;
    int currentCPULoad = 0;
    priority_queue<vector<int>, vector<vector<int>>, endCompare> minHeap;
    for (auto job : arr) {
            // Loop to remove all jobs from the heap which is ended
            // Loop when the stack is not empty and start time of current job is lesser
            // than the job in front of the queue
            while (!minHeap.empty() && job[0] > minHeap.top()[1]) {
                currentCPULoad -= minHeap.top()[2];
                minHeap.pop();
            }
 
            // Add the current Job to CPU
            minHeap.push(job);
            currentCPULoad += job[2];
            maxCPULoad = max(maxCPULoad, currentCPULoad);
        }
        return maxCPULoad;
}

//Approach 2, Same time and space complexity as above

bool comp(const vector<int>& a, const vector<int>& b) {
    if (a[0]!=b[0]) return a[0]<b[0];
    return a[2] == 1 && b[2] == 0;
}

int maxCpuLoad(vector<vector<int>> v)
{
    int count = 0, result = 0; 
    vector<vector<int>> data;
 
    for (int i = 0; i < v.size(); i++) {
        data.push_back({v[i][0],v[i][2],1});
        data.push_back({v[i][1],v[i][2],0});
    }
 
    sort(data.begin(), data.end(), comp);
 
    for (int i = 0; i < data.size(); i++) {
        if (data[i][2] == 1) {
            count += data[i][1];
            result = max(result, count);
        }
        else
            count -= data[i][1];
    }
    return result;
}

int main() {
    vector<vector<int>> arr({{1, 4, 3}, {2, 5, 4}, {7, 9, 6}});
    cout<<max_load(arr);
    return 0;
}