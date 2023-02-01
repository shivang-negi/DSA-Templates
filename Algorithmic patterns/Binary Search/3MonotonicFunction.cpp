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

int main() {
    return 0;
}