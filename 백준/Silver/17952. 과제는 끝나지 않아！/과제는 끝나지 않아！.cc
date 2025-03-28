#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int score = 0;
    stack<int> AStack;
    stack<int> TStack;
    for(int i = 0; i < N; i++){
        int isAssignment, A, T;
        cin >> isAssignment;
        if(isAssignment == 1) {
            cin >> A >> T;
            AStack.push(A);
            TStack.push(T);
        }
        
        if(!TStack.empty()) {
            TStack.top()--;
            if(TStack.top() == 0) {
                score += AStack.top();
                AStack.pop();
                TStack.pop();
            }
        }
    }
    
    cout << score << '\n';
    
	return 0;
}