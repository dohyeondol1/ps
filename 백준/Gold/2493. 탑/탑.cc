#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> height(N + 1);
    vector<int> answer(N + 1, 0);

    for(int i = 1; i <= N; i++)
        cin >> height[i];

    stack<pair<int, int>> s;

    for(int i = 1; i <= N; i++) {
        while(!s.empty() && s.top().second < height[i]) {
            s.pop();
        }
        if(!s.empty()) answer[i] = s.top().first;
      
        s.push({i, height[i]});
    }

    for(int i = 1; i <= N; i++) {
        cout << answer[i];
        if(i < N) cout << ' ';
    }

    return 0;
}