#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, X;
    cin >> N;
    
    string order;
    queue<int> array;
    for(int i = 0; i < N; i++ ) {
        cin >> order;
        if(order == "push"){
            cin >> X;
            array.push(X);
        }
        else if(order == "pop") {
            if(array.empty()) cout << "-1" << '\n';
            else {
                cout << array.front() << '\n';
                array.pop();
            }
        }
        else if(order == "size") {
            cout << array.size() << '\n';
        }
        else if(order == "empty") {
            cout << array.empty() << '\n';
        }
        else if(order == "front"){
            if(array.empty()) cout << "-1" << '\n';
            else cout << array.front() << '\n';
        }
        else if(order == "back") {
            if(array.empty()) cout << "-1" << '\n';
            else cout << array.back() << '\n';
        }
    }

    return 0;
}