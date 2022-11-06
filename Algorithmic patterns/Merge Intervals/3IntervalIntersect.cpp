#include<bits/stdc++.h>
using namespace std;

/*https://leetcode.com/problems/interval-list-intersections/

    If two intervals don't intersect
            b    a
        _____    _______ 
    max of their starting point(a) will be higher the min of their ending point(b).

    If they do intersect
                    b
            _________
                  __________   
                  a
    
    than a<=b
*/

vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
    vector<vector<int>> res;
    int i=0,j=0;
    int n = first.size(), m =second.size();

    while(i<n && j<m) {
        int low  = max(first[i][0],second[j][0]);
        int high = min(first[i][1],second[j][1]);
        
        if(low<=high) res.push_back({low,high});

        if(first[i][1]<second[j][1]) i++;
        else j++;
    }
    return res;
}


int main() {
    
    return 0;
}