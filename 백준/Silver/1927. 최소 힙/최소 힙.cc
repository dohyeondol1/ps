#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        if(x == 0) {
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
    
    return 0;
}