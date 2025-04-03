#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    queue<int> queue;
    for(int i = 1; i <= N; i++)
        queue.push(i);
    
    cout << "<";
    while(queue.size() > 1) {
        for(int i = 1; i < K; i++) {
            queue.push(queue.front());
            queue.pop();
        }
        cout << queue.front() << "," << " ";
        queue.pop();
    }
    cout << queue.front() << ">";
    
    return 0;
}