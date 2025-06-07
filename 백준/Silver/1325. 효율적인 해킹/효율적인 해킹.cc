#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int current, const vector<vector<int>> &graph, vector<bool>& visited) {
    visited[current] = true;
    int count = 1;
    
    for(int next : graph[current]) {
        if(!visited[next])
            count += dfs(next, graph, visited);
    }
    
    return count;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> trust(N+1);
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        trust[B].emplace_back(A);
    }
    
    vector<int> canHackCount(N+1);
    int maxHackCount = 0;
    for(int i = 1; i <= N; i++) {
        vector<bool> visited(N+1, false);
        canHackCount[i] = dfs(i, trust, visited);
        maxHackCount = max(maxHackCount, canHackCount[i]);
    }

    for(int i = 1; i <= N; i++)
        if(canHackCount[i] == maxHackCount) cout << i << ' ';

    return 0;
}