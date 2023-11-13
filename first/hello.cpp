#include <iostream>
using namespace std;

int main () {
    int a,b;
    cout << "Nhap 2 cai coc" << endl;
    cin >> a >> b;
    int c = 1;

    int i = 0;
    while (i < 10)
    {
        c = c * a;
        i++;
    }

    for (int i = 0; i < 10; i++) {
        c = c * a;
    }
    

    cout << c;

    int c;
    c = a * b;
    cout << "Cai coc nay chua" << endl << c;
    return 0;
}