#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    string order[N];
    
    int stack[10000];
    int top = -1;
    
    for(int i = 0; i < N; i ++) {
        cin >> order[i];
        
        int push_number;
        if(order[i] == "push") {
            cin >> push_number;
            top++;
            stack[top] = push_number;
        }
        else if(order[i] == "pop") {
            if(top == -1) cout << -1;
            else {
                cout << stack[top];
                top--;
            }
            
            cout << '\n';
        }
        else if(order[i] == "size") {
            if(top == -1) cout << top+1;
            else cout << top+1;
            
            cout << '\n';
        }
        else if(order[i] == "empty") {
            if(top == -1) cout << 1;
            else cout << 0;
            
            cout << '\n';
        }
        else if(order[i] == "top") {
            if(top == -1) cout << -1;
            else cout << stack[top];
            
            cout << '\n';
        }
    }
    
    return 0;
}