#include <bits/stdc++.h>
using namespace std;

string process(string s){
    string answer;
    int i = 0;
    while(i < s.length()){
        switch(s[i]){
            case 'b':
                for (int j = answer.length(); j >= 0; j--){
                    if (islower(answer[j])){
                        answer.erase(j,1);
                        break;
                    }
                }
                cout << answer << "\n";
            case 'B':
                for (int j = answer.length(); j >= 0; j--){
                    if (isupper(answer[j])){
                        answer.erase(j,1);
                        break;
                    }
                }
                cout << answer << "\n";
            default:
                answer += s[i];
                cout << answer << "\n";
        }
        i++;
    }
    return answer;
}

int main(){
    int t;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> s;
        cout << process(s);
    }
    return 0;
}
