#include <bits/stdc++.h>

using namespace std;

// t number of test case
// s current rook position
// return all possible rook move

int t;
string s;
vector<string> ans;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> s;               //d4
        char row = s[1];        //4
        char col = s[0];        //d

        for (char i = '1'; i <= '8'; i++) {
            ans.clear();
            if (i != row) {
                ans.push_back(col + string(1, i));
                cout << ans[0] << '\n';
            }
        }

        for (char i = 'a'; i <= 'h'; i++) {
            ans.clear();
            if (i != col) {
                ans.push_back(string(1, i) + row);
                cout << ans[0] << '\n';
            }
        }
        
    }

    return 0;
}