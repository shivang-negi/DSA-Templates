#include <bits/stdc++.h>
using namespace std;
 
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int> &storeNode) {
    storeNode.push_back(node);
    vis[node] = 1;
    for(int x: adj[node]) {
        if(!vis[x])
            dfs(x,vis,adj,storeNode);
    }
}

vector<int> sove(vector<int>adj[], int V) {
    vector<int> vis(V+1,0);
    vector<int> storeNode;
    for(int i=0;i<V;i++) {
        if(!vis[i]) 
            dfs(i,vis,adj,storeNode);
    }
    return storeNode;
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
    vector<int> a = sove(adj, V);
    for(int x: a)
        cout<<x<<" ";
    return 0;
}
