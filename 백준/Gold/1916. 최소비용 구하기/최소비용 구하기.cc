#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);
    for(int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    int start, end;
    cin >> start >> end;

    vector<int> distance(N + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    distance[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if(distance[current] < cost) continue;

        for(auto [next, weight] : graph[current]) {
            if(distance[current] + weight < distance[next]) {
                distance[next] = distance[current] + weight;
                pq.push({distance[next], next});
            }
        }
    }

    cout << distance[end] << '\n';
    return 0;
}