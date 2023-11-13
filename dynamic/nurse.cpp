// Đếm số xâu nhị phân độ dài n sao cho
// - ko chứa 2 số 0 liên tiếp
// - các đoạn số 1 liền nhau có độ dài >= k1, <= k2

// Bài toán con:
// Đếm số xâu nhị phân độ dài i thỏa mãn yêu cầu: dp(i)
// dp(i,0): Đếm số xâu nhị phân độ dài i kết thúc bởi 0 thỏa mãn yêu cầu
// dp(i,1): Đếm số xâu nhị phân độ dài i kết thúc bởi 1 thỏa mãn yêu cầu
// Trường hợp cơ sở: 
//      dp(0,0) = 1  
//      dp(0,1) = 1

// dp(i,0) = dp(i-1,1)
// dp(i,1) = sum(j = i - K2 -> i - K1) (dp(j,0))

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int MOD = 1e9 + 7; 
int n, k1, k2;
int mem[N][2];

int dp(int i, int work) {
    if (i == 0 )
        return mem[i][work] = 1;
        if (mem[i][work])
            return mem[i][work];
        int res = 0;
        if (work ==  0) {
            res = dp(i-1, 1);
        }
        else {
            for (int j = i - k2; j <= i-k1; j++)
                if (j >= 0)
                    res =(res + dp(j,0)) % MOD ;
        }
        return mem[i][work] = res;
}

int main(){
    memset(mem, 0, sizeof(mem));
    cin >> n >> k1 >> k2;
    cout << dp(n,0) + dp(n,1) << endl;
    return 0;
}
