#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int prim(int N, const vector<vector<pair<int, int>>>& adj) {
    vector<bool> visited(N, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    int totalWeight = 0;
    pq.push({0, 0});
    
    while(!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();
        
        if(visited[u]) continue;
        visited[u] = true;
        totalWeight += weight;
        
        for(auto& [w, v] : adj[u]) {
            if(!visited[v])
                pq.push({w, v});
        }
    }
    
    return totalWeight;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N);
    
    for(int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        
        u--; v--;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    
    int answer = prim(N, adj);
    cout << answer << '\n';
    return 0;
}