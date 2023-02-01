#include<bits/stdc++.h>
using namespace std;

int lower_bound(int arr[], int N, int X) {
    int low = 0, high = N;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (X <= arr[mid]) high = mid;
        else low = mid + 1;
    }
   
    if(low < N && arr[low] < X) low++;
    return low;
}
 
int upper_bound(int arr[], int N, int X) {
    int low = 0, high = N;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (X >= arr[mid]) low = mid + 1;
        else high = mid;
    }
   
    if(low < N && arr[low] <= X) low++;
    return low;
}
 

int main() {
    int arr[] = {1,6,6,6,12,13,15};
    cout<<lower_bound(arr,7,6);
    cout<<" "<<upper_bound(arr,7,11);
    return 0;
}

//Lower bound is greater than or equal to
//Upper bound is greater than