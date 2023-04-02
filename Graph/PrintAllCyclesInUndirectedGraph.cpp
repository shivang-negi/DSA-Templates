// C++ program to print all the cycles
// in an undirected graph
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;

vector<int> graph[N];
vector<vector<int>> cycles;

void dfs_cycle(int u, int p, int color[], int par[], int& cyclenumber) {
	if (color[u] == 2) {
		return;
	}
	if (color[u] == 1) {
		vector<int> v;
		cyclenumber++;
		
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
		dfs_cycle(v, u, color, par, cyclenumber);
	}

	color[u] = 2;
}

void addEdge(int u, int v) {
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void printCycles(int& cyclenumber)
{
	for (int i = 0; i < cyclenumber; i++) {
		cout << "Cycle Number " << i + 1 << ": ";
		for (int x : cycles[i])
			cout << x << " ";
		cout << endl;
	}
}

int main() {
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(3, 4);
	addEdge(4, 6);
	addEdge(4, 7);
	addEdge(5, 6);
	addEdge(3, 5);
	addEdge(7, 8);
	addEdge(6, 10);
	addEdge(5, 9);
	addEdge(10, 9);
	addEdge(10, 11);
	addEdge(11, 12);
	addEdge(11, 13);
	addEdge(12, 13);

	int color[N];
	int par[N];

	int cyclenumber = 0;
	int edges = 6;

	dfs_cycle(1, 0, color, par, cyclenumber);

	printCycles(cyclenumber);
    return 0;
}
