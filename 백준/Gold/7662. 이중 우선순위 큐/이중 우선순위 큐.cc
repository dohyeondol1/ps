#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int T;
    cin >> T;
    while(T--) {
        int k;
        cin >> k;

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_map<int, int> count;

        for(int i = 0; i < k; i++) {
            char cmd;
            int n;
            cin >> cmd >> n;

            if(cmd == 'I') {
                maxHeap.push(n);
                minHeap.push(n);
                count[n]++;
            }
            if(cmd == 'D') {
                if(n == 1) {
                    while(!maxHeap.empty() && count[maxHeap.top()] == 0) 
                        maxHeap.pop();
                    if(!maxHeap.empty()) {
                        count[maxHeap.top()]--;
                        maxHeap.pop();
                    }
                } 
                if(n == -1) {
                    while(!minHeap.empty() && count[minHeap.top()] == 0) 
                        minHeap.pop();
                    if(!minHeap.empty()) {
                        count[minHeap.top()]--;
                        minHeap.pop();
                    }
                }
            }
        }

        while(!maxHeap.empty() && count[maxHeap.top()] == 0) 
            maxHeap.pop();
        while(!minHeap.empty() && count[minHeap.top()] == 0) 
            minHeap.pop();

        if(maxHeap.empty() || minHeap.empty()) cout << "EMPTY" << '\n';
        else cout << maxHeap.top() << ' ' << minHeap.top() << '\n';
    }

    return 0;
}