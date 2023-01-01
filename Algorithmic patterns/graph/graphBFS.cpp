#include <bits/stdc++.h>
using namespace std;
 
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    vector<int> vis(V,0);
    for (int v = 0; v < V; ++v) {
        if(!vis[v]) {
            queue <int> q;
            q.push(v);
            vis[v] = 1;
            while(!q.empty()) {
                int num = q.front();
                int n = q.size();
                cout<<num<<" ";
                q.pop();
                for(auto x: adj[num]) {
                    if(!vis[x]) {
                        q.push(x);
                        vis[x] = 1;
                    }
                }
            }            
        }
    }
}
 
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}