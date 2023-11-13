#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    std::cout << "Hello World" << std::endl;

    std::cout << "yolo" << std::endl;

    vector<string> msg {"My", "Balls", "are", "itching"};
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}