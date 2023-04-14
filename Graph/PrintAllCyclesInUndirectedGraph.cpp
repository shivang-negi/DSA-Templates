// C++ program to print all the cycles
// in an undirected graph
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;

vector<int> graph[N];
vector<vector<int>> cycles;

void dfs_cycle(int u, int p, int color[], int par[]) {
	if (color[u] == 2) {
		return;
	}
	if (color[u] == 1) {
		vector<int> v;
		
		int cur = p;
		v.push_back(cur);

		while (cur != u) {
			cur = par[cur];
			v.push_back(cur);
		}
		cycles.push_back(v);
		return;
	}
	par[u] = p;
	color[u] = 1;

	for (int v : graph[u]) {
		if (v == par[u]) {
			continue;
		}
		dfs_cycle(v, u, color, par);
	}

	color[u] = 2;
}

void addEdge(int u, int v) {
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void printCycles()
{
	for (int i = 0; i < cycles.size(); i++) {
		cout << "Cycle Number " << i + 1 << ": ";
		for (int x : cycles[i])
			cout << x << " ";
		cout << endl;
	}
}

int main() {
	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(3, 5);
	addEdge(1, 5);
	addEdge(2, 4);
	addEdge(4, 5);

	int color[N];
	int par[N];

	int start = 1, end = 5;

	for(int i=start;i<=end;i++) {
		if(color[i]==0) {
			dfs_cycle(i, 0, color, par);
		}
	}
	printCycles();
    return 0;
}
