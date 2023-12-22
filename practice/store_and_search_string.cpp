#include <bits/stdc++.h>

using namespace std;

vector<string> v;
string s;


bool find_query(string s) {
    if (find(v.begin(), v.end(), s) != v.end()) {
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
        v.push_back(s);
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
                v.push_back(s);
                cout << "1\n";
            }
        }
       
    }

    
    return 0;
}