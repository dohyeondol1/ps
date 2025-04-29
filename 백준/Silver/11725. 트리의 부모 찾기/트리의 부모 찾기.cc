#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
bool visited[1000000];
int parent[1000000];

void find_parent(int current) {
    visited[current] = true;
    
    for(auto &next : graph[current]) {
        if(!visited[next]) {
            parent[next] = current;
            find_parent(next);   
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    pair<int, int> node;
    graph.resize(N+1);
    while(--N) {
        cin >> node.first >> node.second;
        graph[node.first].push_back(node.second);
        graph[node.second].push_back(node.first);
    }
    
    find_parent(1);

    for(int i = 2; i < graph.size(); i++)
        cout << parent[i] << '\n';

    return 0;
}