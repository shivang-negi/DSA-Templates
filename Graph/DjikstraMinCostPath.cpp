#include<bits/stdc++.h>
using namespace std;

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
        auto x=pq.top();
        pq.pop();
        int cost=x.first;
        auto y=x.second;
        int i=y.first;
        int j=y.second;
        for(int k=0; k<4; k++){
            int u=i+dx[k];
            int v=j+dy[k];
            if(u>=0 && u<n && v>=0 && v<m) {
                if(dist[u][v]>dist[i][j]+ grid[u][v]) {
                    dist[u][v]=dist[i][j]+grid[u][v];
                    pq.push({dist[u][v], {u, v}});
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) 
            cout<<dist[i][j]<<" ";
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

//GRAPH:
void solve() {
	int n,m;
	cin>>n>>m;
 
	vector<pair<int,int>> adj[n];
	int u,v,w;
 
	for(int i=0;i<m;i++) {
		cin>>u>>v>>w;
		u--;v--;
		adj[u].push_back({v,w});
	}
 
	vector<ll> dist(n,LLONG_MAX);
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push({0,0});
	dist[0] = 0;
	vector<int> vis(n,0);
 
	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		ll cost = cur.first;
		ll node = cur.second;
		if(vis[node]) continue;
		vis[node] = 1;
 
		for(auto x: adj[node]) {
			ll c = x.second;
			ll next = x.first;
			if((c + cost) < dist[next]) {
				dist[next] = c + cost;
				pq.push({dist[next],next});
			}
		}
	}
	for(int i=0;i<n;i++) cout<<dist[i]<<" ";
}