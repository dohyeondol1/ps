#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    vector<int> order(N);
    
    stack<int> stack;
    
    for(int i = 0; i < N; i ++) {
        cin >> order[i];
        
        int push_number;
        if(order[i] == 1) {
            cin >> push_number;
            stack.push(push_number);
        }
        else if(order[i] == 2) {
            if(stack.empty()) cout << -1;
            else {
                cout << stack.top();
                stack.pop();
            }
            cout << '\n';
        }
        else if(order[i] == 3) {
            cout << stack.size() << '\n';
        }
        else if(order[i] == 4) {
            cout << stack.empty() << '\n';
        }
        else if(order[i] == 5) {
            if(stack.empty()) cout << -1;
            else cout << stack.top();
            cout << '\n';
        }
    }
    
    return 0;
}