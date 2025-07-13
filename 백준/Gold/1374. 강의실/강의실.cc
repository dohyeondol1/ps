#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;
    vector<pair<int, int>> lectures;
    for(int i = 0; i < N; ++i) {
        int lectureNumber, start, end;
        cin >> lectureNumber >> start >> end;
        lectures.push_back({start, end});
    }

    sort(lectures.begin(), lectures.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    int answer = 0;
    for(auto [start, end] : lectures) {
        while(!pq.empty() && pq.top() <= start) {
            pq.pop();
        }
        pq.push(end);
        answer = max(answer, (int)pq.size());
    }

    cout << answer << '\n';
    return 0;
}