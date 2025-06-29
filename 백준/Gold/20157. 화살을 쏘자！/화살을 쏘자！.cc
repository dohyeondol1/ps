#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<pair<int, int>> balloon(N);
    vector<double> angle(N);
    for(int i = 0; i < N; i++) {
        cin >> balloon[i].first >> balloon[i].second;
        angle[i] = atan2(balloon[i].second, balloon[i].first);
    }
    
    unordered_map<double, int> count;
    for(auto x : angle) count[x]++;

    int answer = 0;
    for(const auto& [val, cnt] : count)
        answer = max(answer, cnt);
    
    cout << answer << '\n';
    return 0;
}