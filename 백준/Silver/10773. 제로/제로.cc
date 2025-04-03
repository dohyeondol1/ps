#include <iostream>
#include <stack>
using namespace std;

int main() {
    int K;
    cin >> K;
    
    stack<int> stack;
    while(K--) {
        int N;
        cin >> N;
        
        stack.push(N);
        if(N == 0) {
            stack.pop();
            stack.pop();
        }
    }
    
    int sum = 0;
    while(!stack.empty()) {
        sum += stack.top();
        stack.pop();
    }
    
    cout << sum << '\n';
    
    return 0;
}