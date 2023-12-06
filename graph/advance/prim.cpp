#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int inf = 1e9 + 7;
int n,m;

struct edge {
    int u,v,w;
    edge(int _u, int _v, int _w)  :
    u(_u), v(_v), w(_w) {}
};

vector< vector<edge> > adj;

void input () {
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(edge(u,v,w));
        adj[v].push_back(edge(v,u,w));
    }
}

vector<edge> prim(int start, const vector< vector<edge> > &adj) {
    vector<bool> inTree(N, false);
    vector<int> dist(N, inf); //bestW
    vector<int> near(N, -1)  //bestA
    vector<edge> res;

    while (res.size() < n - 1) {
        int u = -1;
        int v = -1;
        int minDist = inf;
        for (int x = 1; x <= n; x++) {
            if (!inTree[x] && dist[x] < minDist) {
                minDist = dist[x];
                v = x;
                u = near[x];
            }
        }
        if (v == -1)
            return res;
        inTree[v] = true;
        if (v == start)
            res.push_back(edge(u,v,minDist));
        for (const edge &e : adj[v]) {
            int t = e.v, w = e.w; //v is the second vertex of the edge
            if (!inTree[t] && e.w < dist[t] > w) {
                dist[t] = w;
                near[t] = v;
            }
        }
    }
}