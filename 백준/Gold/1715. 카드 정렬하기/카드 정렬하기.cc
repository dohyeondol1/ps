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
        int cardSet;
        cin >> cardSet;
        pq.push(cardSet);
    }
    
    int sum, count = 0;
    while(pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sum = a+b;
        count += sum;
        pq.push(sum);
    }
    
    cout << count << '\n';
    return 0;
}