#include<bits/stdc++.h>
using namespace std;

bool ispalin(string &str, int i, int j) {
    while(i < j)
    {
        if(str[i] != str[j])
        return false; 
        i++;
        j--;
    }
    return true;
}

int find(string &str, int n, int i, int j, vector<vector<int>>&memo) {
    if(i>=j) return 0;
    if(ispalin(str,i,j)) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
    int min = INT_MAX;
    for(int k=i;k<j;k++) {
        int part = find(str,n,i,k,memo) + find(str,n,k+1,j,memo) + 1;
        if(part<min)
            min = part;
    }
    return memo[i][j] = min;
}

int palindromicPartition(string str)
{
    int n = str.size();
    vector<vector<int>> memo(n,vector<int>(n,-1));
    return find(str,n,0,n-1,memo);
}

int main() {
    cout<<palindromicPartition("mitin");
    return 0;
}