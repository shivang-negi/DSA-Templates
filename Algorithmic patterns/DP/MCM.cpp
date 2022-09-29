#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int find(int p[],int i, int j,vector<vector<int>> &memo) {
    if (i>=j) return 0;
    int min = INT_MAX;
    if(memo[i][j]!=-1) return memo[i][j];
    
    for (int k = i; k < j; k++) {
        int count = find(p,i,k,memo)+find(p,k+1,j,memo)+(p[i - 1]*p[k]*p[j]);
        if (count < min)
            min = count;
    }
    return memo[i][j] = min;
}

int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> memo(N+1,vector<int>(N+1,-1));
    return find(arr,1,N-1,memo);
}

int main() {
    int arr[] = {40,20,30,10,30};
    cout<<matrixMultiplication(5,arr);
    return 0;
}