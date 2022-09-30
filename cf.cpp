#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
	vector<int>ans;
    while(t--) {
        int n,k;
		cin>>n>>k;
		int x;
		vector<int> arr[n+1];
		for(int i=2;i<n+1;i++) {
			cin>>x;
			arr[x].push_back(i);
		}
		vector<int> dep;
		queue<pair<int,int>> q;
		q.push({1,0});
		while(!q.empty()) {
			auto cur = q.front();
			int node = cur.first;
			int depth = cur.second;
			q.pop();
			if(arr[node].size()==0) dep.push_back(depth);
			else {
				for(int x: arr[node]) {
					q.push({x,depth+1});
				}
			}
		}
		sort(dep.begin(),dep.end());
	}
	for(int x: ans) cout<<x<<endl;
    return 0;
}