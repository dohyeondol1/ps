#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    string order; int X;
    deque<int> dq;
    while(N--) {
        cin >> order;
        if(order == "push_front") {
            cin >> X;
            dq.push_front(X);
        }
        if(order == "push_back") {
            cin >> X;
            dq.push_back(X);
        }
        if(order == "pop_front") {
            if(dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        if(order == "pop_back") {
            if(dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        if(order == "size") {
           cout << dq.size() << '\n';
        }
        if(order == "empty") {
            cout << dq.empty() << '\n';
        }
        if(order == "front") {
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        if(order == "back") {
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }

    return 0;
}