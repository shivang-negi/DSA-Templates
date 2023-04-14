#include <bits/stdc++.h>
using namespace std;

//Prints atmost one cycle

const int MAXN = 100005;
 
vector<int> adj[MAXN];
int vis[MAXN], parent[MAXN], cycle_start, cycle_end;
 
bool dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 0) {
            parent[v] = u;
            if (dfs(v)) {
                return true;
            }
        } else if (vis[v] == 1 && parent[u] != v) {
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    vis[u] = 2;
    return false;
}
 
void find_cycle(int n) {
    for (int u = 1; u <= n; u++) {
        if (vis[u] == 0) {
            if (dfs(u)) {
                return;
            }
        }
    }
}
 
int main() {
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    int n, m;
    cin >> n >> m; 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    cycle_start = -1;
	
    find_cycle(n);

    if (cycle_start == -1) cout << "NO CYCLE" << endl;
	else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        int x = cycle_end;
        while (x != cycle_start) {
            cycle.push_back(x);
            x = parent[x];
        }
        cycle.push_back(cycle_start);
        cout<<cycle.size()<<"\n";
        for (int i = cycle.size() - 1; i >= 0; i--) 
            cout << cycle[i] << " ";
    }
    return 0;
}