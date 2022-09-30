#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();  
    sort(nums.begin() , nums.end());
    vector<vector<int>> ans;  
    set<vector<int>> store; 

    for(int i = 0 ; i < n; i++){
        for(int j = i + 1; j < n ; j++) {		
            int x = j+1 , y = n-1;            
            while(x < y){			
                int sum = target - nums[i] - nums[j] + nums[x] + nums[y];                 
                if(sum > 0) y--;
                else if(sum < 0 ) x++;
                else  {
                    store.insert({nums[i] , nums[j] , nums[x] , nums[y]});
                    x++;
                    y--;
                };
            }
        }
    }
    for(auto i : store) ans.push_back(i);  // store the answers in an array(ans)
    return ans;
}

int main() {
    return 0;
}