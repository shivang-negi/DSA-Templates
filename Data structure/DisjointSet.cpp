#include<bits/stdc++.h>
using namespace std;

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void combine (int u, int v) {
    u = find(u);
    v = find(v);
    
    if(u == v) return;   
    else {
        if(size[u] > size[v]) {
            parent[v] = u;
            size[u] += size[v];
        }
        else {
            parent[u] = v;
            size[v] += size[u];
        }
    }
}

/*
    int n,m;
	cin>>n>>m;
	parent.resize(n);
	size.resize(n,0);
	for(int i=0;i<n;i++) parent[i] = i;
	
	int a,b;
	for(int i=0;i<m;i++) {
		cin>>a>>b;
		int p1 = find(a-1);
		int p2 = find(b-1);

		combine(p1,p2);
	}
	for(int i=0;i<n;i++) find(i);   //To get parent of each component
*/

int main() {

    return 0;
}