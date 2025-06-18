#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> p;
    vector<vector<int>> grid(N+1, vector<int>(M+1));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) p.push_back({ j, i });
        }
    }
    
    int x1 = p[0].first;
    int y1 = p[0].second;
    int x2 = p[1].first;
    int y2 = p[1].second;
    
    int D = abs(x2-x1) + abs(y2-y1);
    cout << D << '\n';
    return 0;
}