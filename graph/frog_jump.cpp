#include<iostream>
#include<queue>
#include <climits>
using namespace std;

int n,m;
int grid[100][100];

int find() {
    int ans=0;
    int dist[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dist[i][j]=INT_MAX;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    dist[0][0]=grid[0][0];
    pq.push({0, 0});
    int dx[4]={0, 0, -1, 1};
    int dy[4]={-1, 1, 0, 0};
    while(!pq.empty()) {
        auto y=pq.top(); 
        pq.pop();
        int i=y.first;
        int j=y.second;
        for(int k=0; k<4; k++){
            int u=i+dx[k];
            int v=j+dy[k];
            if(u<0 || u>=n || v<0 ||  v>=m  ) continue;
            if(dist[u][v]>dist[i][j]+ grid[u][v]){
                dist[u][v]=dist[i][j]+grid[u][v];
                pq.push({u, v});
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
    cin>>m>>n;
    for(int i=0;i<m;i++) 
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    int x = find();
    // cout<<x;
    return 0;
}

