#include <bits/stdc++.h>
using namespace std;

//lambda
void solve(vector<int>& arr, int x) {
    int n = arr.size();
    sort(arr.begin(),arr.end(), [x](const int a, const int b) {
        return abs(a-x) < abs(b-x);
    });
    return;
}

//Comparator for multiset & priority queue
void compare() {
    
    //Could be any class template (pair, struct, vector)
    auto cmp = [](const pair<int,int> &x, const pair<int,int> &y) { 
        if(x.first==y.first) return x.second < y.second ;
        return x.first > y.first; 
    };

    auto cmp2 = [](const pair<int,int> &x, const pair<int,int> &y) { 
        return x.second < y.second; 
    };
    
    multiset<pair<int,int>, decltype(cmp)> valid(cmp);
    multiset<pair<int,int>, decltype(cmp2)> invalid(cmp2);

    
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
}

//Quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {4, 2, 8, 3, 1, 5, 7,11,6};
    int size = sizeof(arr) / sizeof(int);

    cout<<"Before Sorting"<<endl;
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout<<"After Sorting"<<endl;
    printArray(arr, size);

    return 0;
}
