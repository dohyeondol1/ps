#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string S;
    getline(cin, S);
    
    stack<char> wordStack;
    bool inTag = false;
    
    for (char SString : S) {
        if (SString == '<') {
            while (!wordStack.empty()) {
                cout << wordStack.top();
                wordStack.pop();
            }
            inTag = true;
            cout << SString;
        } else if (SString == '>') {
            inTag = false;
            cout << SString;
        } else if (inTag) {
            cout << SString;
        } else {
            if (SString == ' ') {
                while (!wordStack.empty()) {
                    cout << wordStack.top();
                    wordStack.pop();
                }
                cout << ' ';
            } else {
                wordStack.push(SString);
            }
        }
    }
    
    while (!wordStack.empty()) {
        cout << wordStack.top();
        wordStack.pop();
    }
    
    return 0;
}