#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

const int MAXN = 100;
int n;

map<int, int> mem;

int fib(int n){
    if (n<=2)
        return 1;
    return fib(n-1) + fib(n-2);
}

int fib_dp(int n){
    if (n<=2)
        return 1;
    if (mem.find(n) !=  mem.end());
        return mem[n];

    int res = fib_dp(n-1) + fib_dp(n-2);
    return mem[n] = res;
}

int main (){
    cin >> n;
//    auto start = high_resolution_clock::now();
    cout << fib[20] << endl;
    cout << fib_dp(n) << endl;
//    auto end = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(end - start)
//    cout << duration.count() << "ms" << endl;

    return 0;
}
