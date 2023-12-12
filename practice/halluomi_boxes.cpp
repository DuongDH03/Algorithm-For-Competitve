#include <bits/stdc++.h>

using namespace std;

int t;
int n, k;
vector<int> a;

// t number of test case
// n number of boxes
// k number of boxes to be sorted non decreasingly
// a[i] number written on the box

// solve print out yes/no, if the boxes can be sorted non decreasingly by k boxes


void solve () {
    // if array is already sorted or k>1, then yes
    // k = 1, array still the same
    if (is_sorted(a.begin(), a.end()) || k > 1) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            //cin >> a[j]; you simply can't do this, cuz there is no a[j] yet
            int val;
            cin >> val;
            a.push_back(val);
        }
        solve();
        
        // reset a
        a.clear();
    }

    return 0;
}