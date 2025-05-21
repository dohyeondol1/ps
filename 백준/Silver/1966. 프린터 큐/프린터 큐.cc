#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int testCase, N, docIndex, importance, count = 0;
    cin >> testCase;
    while(testCase--) {
        count = 0;
        cin >> N >> docIndex;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        
        for(int i = 0; i < N; i++) {
            cin >> importance;
            q.push({ i, importance });
            pq.push(importance);
        }
        
        while(!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            
            if(pq.top() == value) {
                pq.pop();
                count++;
                if(index == docIndex) {
                    cout << count << '\n';
                    break;
                }
            }
            else q.push({ index, value });
        }
    }
    
    return 0;
}