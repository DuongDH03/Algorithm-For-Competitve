#include <bits/stdc++.h>

using namespace std;

int t; //number of test case
string s, res;

//input a string, iterate thru the string
//if meets 'B', delete the rightmost upper case letter of the string till 'B', 
//if meets 'b' delete the rightmost lower case letter of the string till 'b'

int bcount = 0, Bcount = 0;


int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        res.clear();
        bcount = 0;
        Bcount = 0;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == 'B') {
                Bcount++;
            }
            else if (s[i] == 'b') {
                bcount++;
            }
            else if (isupper(s[i]) && Bcount > 0) {
                Bcount--;
            }
            else if (islower(s[i]) && bcount > 0) {
                bcount--;           
            }
            else res += s[i];

        }
        res = string(res.rbegin(), res.rend());
        cout << res << endl;

    }

    return 0;
}