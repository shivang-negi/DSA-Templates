#include<bits/stdc++.h>
using namespace std;


int threeSumClosest(vector<int>& nums, int target) 
{
    int c=nums[0]+nums[1]+nums[2],n=nums.size();
    if(n==3) return c;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++) {
        int front=i+1;
        int back=n-1;
        while(front<back)
        {
            int sum=nums[i]+nums[front]+nums[back];
            if(sum==target) return sum;
            if(abs(target-sum)<abs(target-c))
                c=sum;
            if(sum>target)
                back--;
            else
                front++;
        }
    }
    return c;
}

int main() {

    return 0;
}