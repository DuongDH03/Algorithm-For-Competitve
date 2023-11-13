#include <iostream>

using namespace std;

const int MAXN = 15;
int cnt,n,x[MAXN];

int marked[MAXN];

void print_sol(){
    for (int i=1; i<=n; i++)
        cout<< x[i] << " ";
    cout << endl;
}

bool is_cand (int i, int k){
    if (k<3) return true;
    if (x[k-2] > x[k-1] )
        return true;
    return x[k-1] > i;
}

// BONUS: 3 sequential elements with no ascending order?

void TRY(int k){
    // x[1],x[2],...x[k-1]
    // x[k] != x[i], i = 1,..k-1
    for(int i=1; i<=n; i++){
        if (!marked[i]){
        // FROM BONUS: if ((!marked[i]) && is_cand(i,k) ){
            x[k] =i;
            marked[i] =true;
            if (k ==n){
                print_sol();
                cnt ++;
            }
            else TRY (k+1);
            marked[i] = false;
        }
    }
}

int main (){
    cin >> n;
    TRY(1);
    cout << cnt;
    return 0;
}