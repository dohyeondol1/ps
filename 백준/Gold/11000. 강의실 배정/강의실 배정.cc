#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;
    
    vector<pair<int, int>> t(N);
    priority_queue<int, vector<int>, greater<>> endT; 
    for(int i = 0; i < N; i++)
        cin >> t[i].first >> t[i].second;
    
    sort(t.begin(), t.end());

    for(int i = 0; i < t.size(); i++) {
        endT.push(t[i].second);
        if(endT.top() <= t[i].first) endT.pop();
    }
    
    cout << endT.size() << '\n';
    return 0;
}