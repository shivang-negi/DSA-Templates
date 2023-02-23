#include<bits/stdc++.h>
using namespace std;

/*
Usually, in such problems, we want to find the maximum or minimum value
of x such that f(x) is true.

This can be done with binary search if f(x) satisfies both of the
conditions:

If f(x) =  true, then f(y) =  true for all y<=x.
If f(x) = false, then f(y) = false for all y>=x.

*/

int first_true(int lo, int hi, function<bool(int)> f) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) { //Function f would be a monotonic function
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

void findX(int targetValue) {
    int start = 0, end = targetValue;
    int mid, result;
 
    while (start <= end) {
        mid = start + (end - start) / 2;

        if (mid * mid <= targetValue) {		//	f(x) = x * x
            result = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    cout << result << endl;
}

int main() {
    return 0;
}