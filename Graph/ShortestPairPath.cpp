#include <iostream>
using namespace std;

void floydWarshall() {
	ll n,m;
	cin>>n>>m;

	vector<vector<ll>> graph(n,vector<ll>(n,1e15));
	ll u,v,w;
	for(int i=0;i<m;i++) {
		cin>>u>>v>>w;
		graph[u][u] = 0;
		graph[v][v] = 0;
		graph[u][v] = min(w,graph[u][v]);
		graph[v][u] = min(w,graph[v][u]);
	}

  //Floyd Warshall
	int k = 0, i = 0, j = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (graph[i][k] + graph[k][j] < graph[i][j])
				graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

  ll a,b;
  cin>>a>>b;
  
  cout<<graph[a][b];  //Shortest distance from a to b
}

int main() {
  floydWarshall();
  return 0;
}


 