#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> m;
string s;
int i = 0;


bool find_query(string s) {
    if (m.find(s) != m.end()) {
        return 1;
    } else {
        return 0;
    }   
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        cin >> s;
        if (s == "*") break;
        m[s] = i;
        i++;
    }

    while (true) {
        cin >> s;
        if (s == "***") break;

        if (s == "find") {
            cin >> s;
            cout << find_query(s) << '\n';
        }
        else if (s == "insert") {
            cin >> s;
            if (find_query(s)) {
                cout << "0\n";
            } else {
                m[s] = i;
                i++;
                cout << "1\n";
            }
        }
       
    }

    
    return 0;
}