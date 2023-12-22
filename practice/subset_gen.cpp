#include <bits/stdc++.h>

using namespace std;

int n = 3;
vector<int> subset;

void search(int k) {
    if (k == n) {
        //process subset
        for (auto i : subset)
            cout << i << " ";
        cout << '\n';

    } else {
        search(k+1);
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // generating subset of {0,1,2,3...n-1}
    
    search(0);
    subset.clear();
    cout << endl;


    // generating subset of {0,1,2,3...n-1} using bit manipulation
    for (int b = 0; b < (1 << n); b++) 
        for (int i = 0; i < n; i++)
            if (b & (1 << i))
                subset.push_back(i);
    
    cout << '\n';
    
    for (int b = 0; b < (1 << n); b++) {
        for (int i = 0; i < n; i++)
            if (b & (1 << i))
                cout << i << " ";
        cout << endl;
    }

    return 0;
}