#include<bits/stdc++.h>
using namespace std;

/*
We are given a list scheduleof employees, which represents the working time for each
employee. Each employee has a list of non-overlapping Intervals, and these intervals are 
in sorted order. Return the list of finite intervals representing common, positive-length
free time forallemployees, also in sorted order.

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output:[[3,4]]

Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.

Input:schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output:[[5,6],[7,9]]
*/

//(┛◉Д◉)┛彡┻━┻