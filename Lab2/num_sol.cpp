#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int n, M;
int a[MAX], X[MAX];
int T;
int sol_cnt;

bool check(int v, int k){
    if(k < n)
        return true;
    return T + a[k] * v == M;
}
void solution(){
    sol_cnt ++;
}

void TRY (int k){
    for (int v = 1; v <= M-T - n+k; v++){
        if (check(v,k)){
            X[k] = v;
            T = T + a[k] * X[k];
            if (k == n)
                solution();
            else TRY(k+1);
            T = T - a[k] * X[k];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> M;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    TRY(1);
    cout << sol_cnt;
    return 0;
}