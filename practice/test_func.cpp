#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Demonstrate the use of binary search

    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(array[0]);
    // lower_bound, upper_bound used binary search
    auto k = lower_bound(array, array + n, 3) - array;
    if (k < n && array[k] == 3)
        cout << "Found at k" << endl;
    else
        cout << "Not found" << endl;

    // count the number of elements whose value is 3
    auto a = lower_bound(array, array + n, 3);
    auto b = upper_bound(array, array + n, 3);
    cout << b - a << endl;

    // use equal_range can be shorter:
    auto p = equal_range(array, array + n, 3);
    cout << p.second - p.first << endl;

    


    return 0;
}