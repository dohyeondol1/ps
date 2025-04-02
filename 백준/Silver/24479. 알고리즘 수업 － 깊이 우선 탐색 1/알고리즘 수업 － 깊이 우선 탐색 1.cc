#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<vector<int>> graph;
bool visitedDfs[100001];
int visitedSequence[1000001];
int sequence = 1;

void dfs(int current) {
    visitedDfs[current] = true;
    visitedSequence[current] = sequence++;

    for(int next : graph[current]) {
        if(!visitedDfs[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> R;
    graph.resize(N + 1);

    for(int i = 0; i < M; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(R);
    for(int i = 1; i <= N; i++)
        cout << visitedSequence[i] << '\n';

    return 0;
}