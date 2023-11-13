#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MAXN = 20;

int n;
int x[MAXN]; //x[1],  x[2], ...

void print_sol(){
    for (int i=1; i<=n; i++)
        cout<< x[i] << " ";
    cout << endl;
}

void TRY (int k){
    // x[1], x[2], ..., x[k-1]
    // BONUS: No "0" close 
        // x[k-1] = 0 ==> x[k] = 1
        // x[k-1] = 1 ==> x[k] = {0,1}

    for (int i = 0; i <= 1; i++){     // to be altered 
            // int i= 1-x[k-1] (FROM BONUS) 
        x[k] = i;
        if (k == n)
            print_sol();
        else TRY(k+1);
    }
}

int main(){
    cin >> n;
    TRY(1);

    return 0;
}