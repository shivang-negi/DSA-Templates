#include<bits/stdc++.h>
using namespace std;
// #define pii pair<int,pair<int,int>>
int minimumCostPath(vector<vector<int>>& grid) 
{
    int n=grid.size();
    int m=grid[0].size();
    int dist[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            dist[i][j]=INT_MAX;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
    dist[0][0]=grid[0][0];
    pq.push({dist[0][0], {0, 0}});
    int dx[4]={0, 0, -1, 1};
    int dy[4]={-1, 1, 0, 0};
    while(!pq.empty()) {
        auto x=pq.top(); pq.pop();
        int cost=x.first;
        auto y=x.second;
        int i=y.first;
        int j=y.second;
        for(int k=0; k<4; k++){
            int u=i+dx[k];
            int v=j+dy[k];
            if(u>=0 && u<n && v>=0 &&  v<m  ){
                if(dist[u][v]>dist[i][j]+ grid[u][v]){
                    dist[u][v]=dist[i][j]+grid[u][v];
                    pq.push({dist[u][v], {u, v}});
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return dist[n-1][m-1];
}

int main() {
    vector<vector<int>> grid({{0,0,0,2,0},
                              {2,1,0,1,2},
                              {0,0,2,2,0},
                              {0,1,0,1,2},
                              {2,0,0,0,0}});
    int s = minimumCostPath(grid);
    return 0;
}

/*

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