#include <iostream>
#include <vector>
using namespace std;

bool visited[1000000];
int parent[1000000];

void find_parent(int current, vector<vector<int>> &graph) {
    visited[current] = true;
    
    for(int next : graph[current]) {
        if(!visited[next]) {
            parent[next] = current;
            find_parent(next, graph);   
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    pair<int, int> node;
    vector<vector<int>> graph(N+1);
    
    for(int i = 0; i < N-1; i++) {
        cin >> node.first >> node.second;
        graph[node.first].push_back(node.second);
        graph[node.second].push_back(node.first);
    }
    
    find_parent(1, graph);

    for(int i = 2; i <= N; i++)
        cout << parent[i] << '\n';

    return 0;
}