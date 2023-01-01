#include<bits/stdc++.h>
using namespace std;

/*
Example 1 : Consider the following 3 activities sorted by
by finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};

Answer: A person can perform at most two activities. The 
maximum set of activities that can be executed 
is {0, 2} [ These are indexes in start[] and 
finish[] ]
*/

int activitySelection(vector<int> start, vector<int> end, int n)
{
    pair<int,int> arr[n];
    for(int i=0;i<n;i++) arr[i] = {end[i],start[i]};
    sort(arr,arr+n);
    int ans = 1, c = arr[0].first;
    for(int i=1;i<n;i++) {
        if(arr[i].second>c) {
            c = arr[i].first;
            ans++;
        }
    }
    return ans;
}

int main() {
    cout<<activitySelection({10,12,20},{20,25,30},3);
    return 0;
}