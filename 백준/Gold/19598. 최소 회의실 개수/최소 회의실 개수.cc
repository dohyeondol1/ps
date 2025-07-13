#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;
    vector<pair<int, int>> meeting;
    for(int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;
        meeting.push_back({start, end});
    }

    sort(meeting.begin(), meeting.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    int answer = 0;
    for(auto [start, end] : meeting) {
        while(!pq.empty() && pq.top() <= start) {
            pq.pop();
        }
        pq.push(end);
        answer = max(answer, (int)pq.size());
    }

    cout << answer << '\n';
    return 0;
}