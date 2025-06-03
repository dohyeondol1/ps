#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int node) {
    visited[node] = true;
    for(int next : graph[node])
        if(!visited[next]) dfs(next);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int count = 0;
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            dfs(i);
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}