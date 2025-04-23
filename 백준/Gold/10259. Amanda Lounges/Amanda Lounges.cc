#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> graph[200001];
bool states[2][200001];
bool vis[2][200001];

bool dfs(int node, bool flag, int& cnt, bool state[], bool visited[]) {
    bool isValid = true;
    state[node] = flag;
    visited[node] = true;

    if (flag) cnt++;

    for (auto [next, type] : graph[node]) {
        if((type == 0 && flag) || (type == 2 && !flag)) {
            isValid = false;
        }

        bool nextFlag;
        if (type == 0) {
            nextFlag = false;
        } else if (type == 2) {
            nextFlag = true;
        } else {
            nextFlag = !flag;
        }

        if(visited[next]) {
            if(state[next] != nextFlag) isValid = false;
        } else {
            if(!dfs(next, nextFlag, cnt, state, visited)) isValid = false;
        }
    }

    return isValid;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    int minLounge = 0;

    for(int i = 0; i < n && minLounge >= 0; i++) {
        if(vis[0][i] || vis[1][i]) continue;

        int count0 = 0, count1 = 0;

        if(!vis[0][i]) {
            bool valid0 = dfs(i, false, count0, states[0], vis[0]);
            if (!valid0) count0 = -1;
        }

        if(!vis[1][i]) {
            bool valid1 = dfs(i, true, count1, states[1], vis[1]);
            if (!valid1) count1 = -1;
        }

        if(count0 < 0 && count1 < 0) {
            minLounge = -1;
        } else if(count0 < 0) {
            minLounge += count1;
        } else if(count1 < 0) {
            minLounge += count0;
        } else {
            minLounge += min(count0, count1);
        }
    }

    if(minLounge < 0) cout << "impossible" << '\n';
    else  cout << minLounge << '\n';

    return 0;
}