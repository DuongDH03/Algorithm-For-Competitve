#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+5;

vector<int> Adj[N];
vector<bool> bVisted(N, false);
vector<bool> bMarked (N , false );
int n,m;
int u,v;

/*
void DFS (int u) {
    cout << u << ' ';
    if (bMarked[u])
        return;
    bMarked[u] = true;
    bVisted[u] = true;
    for (int i = 0; i < Adj[u].size; ++i) {
        // (// const // int &v : adj[u])
        // Add const => boost speed 
        int v = Adj[u][i];
        bVisted[u] = true;
        DFS(v);
        // if (!bVisited[v])
        //  dfs(v)
    }
}
*/

void dfs (int u) {
    cout << u << ' ';
    bVisted[u] = true;
    for (const int &v : Adj[u])
        if (!bVisted[v])
            dfs(v);
}

void input () {
    cin >> n >> m;
    int u,v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        Adj[u].push_back(v);
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("adj_gph","r",stdin);
    input();
    for (int u = 1; u <= n; u++)
        if (!bVisted[u])
            dfs(u);

    return 0;

}