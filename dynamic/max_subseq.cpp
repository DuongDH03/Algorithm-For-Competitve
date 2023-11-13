#include <bits/stdc++.h>
#include <cstring>

using namespace std;

const int MAXN =  1e6+5;
int n, a[MAXN], pos = -1;
int mem[MAXN];

int dp(int i){
    if (i == 1)
        return a[1];
    if (mem[i] != -1)
        return mem[i];
    int res = max(a[i], a[i] + dp(i - 1));

    return mem[i] = res;
}

int solve(){
    int ans = a[1];      
    for (int i = 1; i<=n; i++){
        if (ans < dp(i)){
            ans = dp(i);
            pos = i;
        }
    }
    return ans;
}

void trace(int i){
    if (i < 1)
        return;
    if (mem[i] == a[i] + mem[i-1])
        trace(i-1);
    cout << a[i] << ' ';
}


int main (){
    memset(mem, -1, sizeof(mem));
    freopen("data.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i<=n; i++)
        cin >> a[i];

    cout << solve() << endl;
    trace(pos);
    cout << endl;
        
    return 0;
}