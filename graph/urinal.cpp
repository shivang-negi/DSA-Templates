#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int mat[n] = {0};
    priority_queue<vector<int>> q;
    vector<int> temp;
    int l=1,r=n,coun=1;
    q.push({n,l,r});
    while(!q.empty())
    {
        temp = q.top();
        q.pop();
        int left = temp[1];
        int right = temp[2];
        int mid = (left+right)/2;
        if(temp[0]>0)
        {
            if(right>mid)
            {
                q.push({right-mid,mid+1,right}); // first push right child then left
            }
            if(left<mid)
            {
                q.push({mid-left,left,mid-1});
            }
        }
        mat[mid-1] = coun;
        coun++;
    }
    for(int i=0; i<n; i++)
    {
        cout<<mat[i];
    }
}
