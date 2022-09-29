#include<bits/stdc++.h>
using namespace std;

/*
You are visiting a farm that has a single row of fruit trees arranged from left to 
right. The trees are represented by an integer array fruits where fruits[i] is the 
type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict 
rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There 
is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree 
(including the start tree) while moving to the right. The picked fruits must fit in one 
of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Example 2:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Example 3:
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

TLDR - Find the longest substring with atmost 2 distinct elements.
*/

int totalFruit(vector<int> fruits) {
    int n = fruits.size();
    int l = 0, r = 0;
    int mx = 0;
    unordered_map<int,int> mp;
    while(r<n) {
        mp[fruits[r]]++;
        while(mp.size()>2) {
            mp[fruits[l]]--;
            if(mp[fruits[l]]==0) mp.erase(fruits[l]);
            l++;
        }
        mx = max(mx, r-l+1);
        r++;
    }
    return mx;
}

int main() {
    cout<<totalFruit({1,2,2,1,3,1,3,3,1});
    return 0;
}

//Alternate solution with only two variable

int totalFruit(int tree[],int n) {
    int lastFruit = -1;
    int secondLastFruit = -1;
    int lastFruitCount = 0;
    int currMax = 0;
    int mx = 0;
    
    for (int i=0;i<n;i++) {
        int fruit = tree[i];
        if (fruit == lastFruit || fruit == secondLastFruit)
            currMax++;
        else
            currMax = lastFruitCount + 1; // last fruit + new fruit
        
        if (fruit == lastFruit)
            lastFruitCount++;
        else
            lastFruitCount = 1; 
        
        if (fruit != lastFruit) {
            secondLastFruit = lastFruit;
            lastFruit = fruit;
        }
        
        mx = max(mx, currMax);
    }
    return mx;
}