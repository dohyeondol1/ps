#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
int erased, result = 0;

void dfs(int current) {
    if(current == erased) return;

    bool isLeaf = true;
    for(auto &next : graph[current]) {
        if (next == erased) continue;
        isLeaf = false;
        dfs(next);
    }
    
    if(isLeaf) result++;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    graph.resize(N+1);
    vector<int> parent(N);
    int root = -1;
    
    for(int i = 0; i < N; i++) {
        cin >> parent[i];
        if (parent[i] == -1) root = i;
        else graph[parent[i]].push_back(i);
    }
    
    cin >> erased;
    
    if(erased == root) cout << 0 << '\n';
    else {
        dfs(root);
        cout << result << '\n';
    }
    
    return 0;
}