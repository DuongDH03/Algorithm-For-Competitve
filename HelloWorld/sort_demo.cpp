#include <iostream>
#include <algorithm>

using namespace std;

int a[]= { 1, 15, 6, 234 ,23};

int main(){
    for(int i=0; i<5; i++)
        cout << a[i] << ' ';
    
    cout<< "\n";
    sort(a,a+5);
    for(int i=0; i<5; i++)
        cout << a[i] << ' ';
    return 0;
}