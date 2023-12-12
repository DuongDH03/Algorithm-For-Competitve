#include <bits/stdc++.h>

using namespace std;

// t number of test case
// n length of string
// s string

// s with all "1" => NO
// s with all "0" => YES
// s with "1" but "0" next to it => YES

int t, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> s;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                flag = false;
            }
            else {
                if (s[i-1] == '1' || s[i+1] == '1') {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }

    return 0;
}

