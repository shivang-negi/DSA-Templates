#include<bits/stdc++.h>
using namespace std;
int n;
int res = INT_MIN;
int dir[5] = {0,1,0,-1,0};
void dfs(vector<vector<int>>& grid,int x, int y,vector<vector<bool>> &vis, int val) 
{
    if(x==n-1 && y==n-1) {
        // cout<<val<<" ";
        res = max(res,val + (grid[n-1][n-1]==2));
        return;    
    }
    for(int i=0;i<4;i++) {
        int nx = x + dir[i];
        int ny = y + dir[i+1];
        if(nx<0 || ny<0 || nx>=n || ny>=n || vis[nx][ny] || grid[nx][ny]==1) continue;
        vis[nx][ny] = true;
        dfs(grid,nx,ny,vis,val + (grid[nx][ny]==2));
        vis[nx][ny] = false;
    }
}

int main() {
    vector<int> arr;
    int t;
    cin>>t;
    while (t--)
    {
        res = INT_MIN;
        cin>>n;
        vector<vector<int>> grid(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vis[0][0] = true;
        dfs(grid,0,0,vis,0);
        arr.push_back(res);
    }
    for(int x: arr)
        cout<<x<<" ";
    return 0;
}

/*
6
0 1 2 1 0 0
0 1 0 0 0 1
0 1 2 1 2 1
0 2 0 1 0 2
0 1 0 1 0 1
2 0 2 1 0 0
5
0 0 0 2 0
2 1 0 1 2
0 0 2 2 0
0 1 0 1 2
2 0 0 0 0
GRAPH:
void djikstra(vector<pair<int,int>> arr[],int n, int m, int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1, INT_MAX);
    pq.push({0,src});
    dist[src] = 0;
    parent[src] = -1;
    while(!pq.empty()) {
        int w = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if(x==n) break;
        for(auto a: arr[x]) {
            int nw = a.first;
            int nx = a.second;
            if(w + nw < dist[nx]) {
                parent[nx] = x;
                dist[nx] = w + nw;
                pq.push({dist[nx],nx});
            }
        }
    }
    if(dist[n]==INT_MAX)
        {
            cout<<"-1";
            return;
        }
    return dist[n];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> arr[n+1];
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        arr[u].push_back({w,v});
    }
    djikstra(arr,n,m,1);
    // cout<<a;
    return 0;
}
}
*/