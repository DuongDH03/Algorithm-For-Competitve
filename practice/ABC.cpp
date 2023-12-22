#include <bits/stdc++.h>

using namespace std;

vector< vector<char> > adj;

void input() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; i < 3; i++) {
            char c;
            cin >> c;
            adj[i][j] = c;
        }
}

void solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    for (int i = 0; i < 3; i++)
        for (int j = 0; i < 3; i++) {
            cout << adj[i][j];
        }

    return 0;
}