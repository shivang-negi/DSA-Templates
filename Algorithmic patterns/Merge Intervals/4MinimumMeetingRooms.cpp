#include<bits/stdc++.h>
using namespace std;

/*
Given N lecture timings, with their start time and end time (both inclusive), the task is
to find the minimum number of halls required to hold all the classes such that a single
hall can be used for only one lecture at a given time.

Input: lectures[][] = {{0, 5}, {1, 2}, {1, 10}} 
Output: 3 
All lectures must be held in different halls because 
at time instance 1 all lectures are ongoing.
Input: lectures[][] = {{0, 5}, {1, 2}, {6, 10}} 
Output: 2 
*/

int minHalls(int lectures[][2], int n)
{
    // Initialize a vector of pair, Time, first value
    // indicates the time of entry or exit of a lecture
    // second value denotes whether the lecture starts or
    // ends
    vector<pair<int, int> > Time;

    for (int i = 0; i < n; i++) {
        Time.push_back({ lectures[i][0], 1 });
        Time.push_back({ lectures[i][1], -1 });
    }

    sort(Time.begin(), Time.end());
 
    int answer = 0, sum = 0;
    for (int i = 0; i < Time.size(); i++) {
        sum = sum + Time[i].second;
        answer = max(answer, sum);
    }
    return answer;
}
 

int main() {

    return 0;
}