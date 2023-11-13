#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+5;

vector<int> Adj[N];
vector<int> compId(N, -1);
int n,m, curID = 1;

void input () {
    cin >> n >> m;
    int u,v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
}

void dfs (int u) {
    compId[u] = curID;
    for (const int &v : Adj[u])
        if (compId[v] ==  -1)
            dfs(v);
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("cmp","r",stdin);
    input();
    for (int u = 1; u <= n; u++)
        if (compId[u] == -1){
            dfs(u);
            curID++;
        }
            
    for (int u = 1; u <= n; u++) {
        cout << u << ' ' << compId[u] << endl;
    }

    return 0;

}
