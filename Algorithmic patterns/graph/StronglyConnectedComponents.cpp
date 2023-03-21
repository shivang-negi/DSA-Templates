#include <bits/stdc++.h>
using namespace std;

/*
A strongly connected component is the portion of a directed graph in which 
there is a path from each vertex to another vertex. It is applicable only on 
a directed graph.
*/

class Graph {
  int V;
  list<int> *adj;
  void fillOrder(int s, bool visitedV[], stack<int> &Stack);
  void DFS(int s, bool visitedV[],vector<vector<int>>&ans, int index);

   public:
  Graph(int V);
  void addEdge(int s, int d);
  vector<vector<int>> getSCC();
  Graph transpose();
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

// DFS
void Graph::DFS(int s, bool visitedV[], vector<vector<int>> &arr, int index) {
  visitedV[s] = true;
  arr[index].push_back(s);

  list<int>::iterator i;
  for (i = adj[s].begin(); i != adj[s].end(); ++i)
    if (!visitedV[*i])
      DFS(*i, visitedV,arr,index);
}

// Transpose
Graph Graph::transpose() {
  Graph g(V);
  for (int s = 0; s < V; s++) {
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i) {
      g.adj[*i].push_back(s);
    }
  }
  return g;
}

// Add edge into the graph
void Graph::addEdge(int s, int d) {
  adj[s].push_back(d);
}

void Graph::fillOrder(int s, bool visitedV[], stack<int> &Stack) {
  visitedV[s] = true;

  list<int>::iterator i;
  for (i = adj[s].begin(); i != adj[s].end(); ++i)
    if (!visitedV[*i])
      fillOrder(*i, visitedV, Stack);

  Stack.push(s);
}

// Print strongly connected component
vector<vector<int>> Graph::getSCC() {
  stack<int> Stack;
  vector<vector<int>> ans;
  int index = -1;

  bool *visitedV = new bool[V];
  for (int i = 0; i < V; i++)
    visitedV[i] = false;

  for (int i = 0; i < V; i++)
    if (visitedV[i] == false)
      fillOrder(i, visitedV, Stack);

  Graph gr = transpose();

  for (int i = 0; i < V; i++)
    visitedV[i] = false;

  while (Stack.empty() == false) {
    int s = Stack.top();
    Stack.pop();

    if (visitedV[s] == false) {
		ans.push_back({});
		index++;
    	gr.DFS(s, visitedV,ans,index);
    }
  }
  return ans;
}

int main() {
    Graph g(8);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 0);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	g.addEdge(6, 4);
	g.addEdge(6, 7);

  vector<vector<int>> arr = g.getSCC();
	for(auto  x: arr) {
		for(auto y: x) {
			cout<<y<<" ";
		}cout<<"\n";
	}
	return 0;
}