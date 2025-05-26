#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int T, M;
    cin >> T;
    
    while(T--) {
        cin >> M;
        cout << (M+1)/2 << '\n';

        vector<int> arr(M+1);
        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        
        for(int i = 1; i <= M; i++) {
            cin >> arr[i];

            if(i%2 == 1) max_pq.push(arr[i]);
            else min_pq.push(arr[i]);
            
            if(!min_pq.empty() && max_pq.top() > min_pq.top()) {
                int a = max_pq.top(); max_pq.pop();
                int b = min_pq.top(); min_pq.pop();
                max_pq.push(b);
                min_pq.push(a);
            }

            if(i%2 == 1) cout << max_pq.top() << '\n';
        }
    }

    return 0;
}