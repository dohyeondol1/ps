#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[30001];
int dist[30001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int V, E, K;
    cin >> V >> E >> K;

    for(int i = 0; i <= V; i++) 
        dist[i] = 1e9;

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[K] = 0;
    pq.push({ 0, K });

    while(!pq.empty()) {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if(dist[current] < cost) continue;

        for(auto& next : graph[current]) {
            int nextNode = next.first;
            int nextCost = cost + next.second;

            if(nextCost < dist[nextNode]) {
                dist[nextNode] = nextCost;
                pq.push({ nextCost, nextNode });
            }
        }
    }

    for(int i = 1; i <= V; i++) {
        if(dist[i] == 1e9) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}