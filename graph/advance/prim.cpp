#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int inf = 1e9 + 7;
int n,m;

struct edge {
    int u, v, w;
    edge(int _u, int _v, int _w)  :
    u(_u), v(_v), w(_w) {}
};

vector< vector<edge> > adj;

void input () {
    cin >> n >> m;
    int u, v, w;
    adj = vector< vector<edge> >(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(edge(u,v,w));
        adj[v].push_back(edge(v,u,w));
    }
}

vector<edge> prim(int start, const vector< vector<edge> > &adj) {
    int n = adj.size() - 1;
    vector<bool> inTree(n + 5, false);  
    vector<int> dist(n + 5, inf); //bestW
    vector<int> near(n + 5, -1);  //bestA
    dist[start] = 0;
    vector<edge> res;

    while (res.size() < n - 1) {
        int u = -1;
        int v = -1;
        int minDist = inf;
        for (int x = 1; x <= n; x++) {  //iterate through edge outside of the tree
            if (!inTree[x] && dist[x] < minDist) {
                minDist = dist[x];
                v = x;
                u = near[v];
            }
        }
        if (v == -1)
            return res; //graph is not connected
        inTree[v] = true;
        if (v != start)
            res.push_back(edge(u,v,minDist));
        for (const edge &e : adj[v]) {  //update the vertex and the dist outside graph
            int u = e.v, w = e.w; //v = e.u - first vertex of the edge
            if (dist[u] > w) {
                dist[u] = w;
                near[u] = v;
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("graph_inp", "r", stdin);
    input();
    vector<edge> res = prim(1, adj);
    for (const edge &e : res) {
        cout << e.u << ' ' << e.v << ' ' << e.w << '\n';
    }
    return 0;
}