#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    char str[101];

    while(true) {
        cin.getline(str, 101);
        if(strcmp(str, ".") == 0) break;

        stack<char> stack;
        bool balance = true;

        for(int i = 0; i < strlen(str); ++i) {
            if(str[i] == '(' || str[i] == '[') {
                stack.push(str[i]);
            }
            else if (str[i] == ')') {
                if(stack.empty() || stack.top() != '(') {
                    balance = false;
                    break;
                }
                stack.pop();
            }
            else if(str[i] == ']') {
                if(stack.empty() || stack.top() != '[') {
                    balance = false;
                    break;
                }
                stack.pop();
            }
        }

        if(balance && stack.empty()) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}