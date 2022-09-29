#include<bits/stdc++.h>
using namespace std;

//Shortest Distance in undirect graph with unit weights

void BFS(vector<int> adj[], int N, int src) 
{ 
	int dist[N];
	for(int i = 0;i<N;i++) dist[i] = INT_MAX; 
	queue<int>  q;
	
	dist[src] = 0;
	q.push(src); 

	while(q.empty()==false) 
	{ 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:adj[node]){
		    if(dist[node] + 1 < dist[it]){
		        dist[it]=dist[node]+1;
		        q.push(it);
		    }
		} 
	} 
	for(int i = 0;i<N;i++) cout << dist[i] << " "; 	
} 

int main()
{

    int N = 6;

    vector<int> adj[5 + 1];

    adj[5].push_back(2);
    adj[2].push_back(5);
    adj[5].push_back(0);
    adj[0].push_back(5);
    adj[4].push_back(0);
    adj[0].push_back(4);
    adj[4].push_back(1);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(1);
    adj[1].push_back(3);

    BFS(adj, 6, 0);

    return 0;
}