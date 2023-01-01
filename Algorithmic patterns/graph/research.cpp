#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,k;
int arr[100][100];
pair<int,int> rare[6];
int dir[5] = {0,1,0,-1,0};
struct Node{
    int x;int y;int lvl;
};

int max(int a, int b) {
    if(a<b)
        return b;
    return a;
}

int get_ans(int sx,int sy) {
    queue<Node> q;
    vector<vector<int>> vis(n,vector<int>(n,0));
    vector<vector<int>> dis(n,vector<int>(n,99999));
    Node a;
    a.x = sx;
    a.y = sy;
    a.lvl = 0;
    vis[sx][sy] = 1;
    dis[sx][sy] = 0;
    q.push(a);
    while(!q.empty()) {
        Node fr = q.front();
        int x = fr.x;
        int y = fr.y;
        int cst = fr.lvl;
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = x + dir[i];
            int ny = y + dir[i+1];
            if(nx<0 || ny<0 || nx==n || ny==n || vis[nx][ny] || arr[nx][ny]==0) continue;
            Node nw;
            nw.x = nx;
            nw.y = ny;
            nw.lvl = cst + 1;
            dis[nx][ny] = nw.lvl;
            vis[nx][ny] = 1;
            q.push(nw);
        }
    }
    int c = -1;
    for(int i=0;i<k;i++) {
        pair<int,int> p = rare[i];
        if(dis[p.first-1][p.second-1]==99999) {
            return -1;
        }
        c = max(c,dis[p.first-1][p.second-1]);
    }
    return c;
}

int main() {
    vector<int> res;
    int t;
    cin>>t;
    for(int test=1;test<=t;test++) {
        cin>>n>>k;
        for(int i=0;i<k;i++) {
            int u,v;
            cin>>u>>v;
            rare[i] = {u,v};
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        }
        int c = 99999;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(arr[i][j]==1) {
                    int x = get_ans(i,j);
                    if(x==-1) continue;
                    c = min(c,x);
                }
            }
        }
        res.push_back(c);
    }
    for(auto v: res) {
        cout<<"#"<<v<<" "<<endl;
    }
    return 0;
}