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

int main() {

    return 0;
}