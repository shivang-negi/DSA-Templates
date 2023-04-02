#include<bits/stdc++.h>
using namespace std;       
//For undirected only
void dfs(int src, int parent, vector <int> &s, int vis[], vector <vector <int>> &graph){
	vis[src] = 1;
	s.push_back(src);
	for(auto &x: graph[src]){
		if(vis[x] == 0){
			dfs(x,src,s,vis,graph);
		}
		else if(vis[x] == 1){
			if(x != parent){
				cout << "cycle \n";
				cout << x << " ";
				int pos = ((int)s.size())-1;
				while(pos >= 0 && s[pos] != x){
					cout << s[pos] << " ";
					--pos;
				}
				cout << "\n";
			}
		}
	}
	vis[src] = 2;
	s.pop_back();
}

int main(){
  int n,m;
  cin >> n >> m;
  vector <vector <int>> graph(n);
  for(int i = 0; i < m; ++i){
	  int a,b;
	  cin >> a >> b;
	  graph[a].push_back(b);
	  graph[b].push_back(a);
  }
  int vis[n] = {0};
  vector <int> s;
  for(int i = 0; i < n; ++i){
	  if(vis[i] == 0){
		  dfs(i,-1,s,vis,graph);
	  }
  }
}

//Sample Input

//12 13
//0 1 
//1 2 
//2 3
//3 4
//4 5
//5 6
//6 7
//7 8
//8 5
//5 9
//9 10
//10 11
//11 3

/*
1->2->3->4->5->4
*/