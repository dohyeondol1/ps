#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> meetings(N);
    
    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    // 람다함수가 킥임!! 람다함수 제대로 알아놓자잉
    sort(meetings.begin(), meetings.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    int count = 0;
    int lastEndTime = 0;
    
    for (int i = 0; i < N; i++) {
        if (meetings[i].first >= lastEndTime) {
            count++;
            lastEndTime = meetings[i].second;
        }
    }

    cout << count << '\n';

    return 0;
}