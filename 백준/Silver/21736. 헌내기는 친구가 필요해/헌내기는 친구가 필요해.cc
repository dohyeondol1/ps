#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<string> campus;
bool visited[601][601];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    int count = 0;
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if(campus[x][y] == 'P') count++;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(visited[nx][ny] || campus[nx][ny] == 'X') continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return count;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> M;
    campus.resize(N);

    int startX, startY;
    for(int i = 0; i < N; i++) {
        cin >> campus[i];
        for(int j = 0; j < M; j++) {
            if(campus[i][j] == 'I') {
                startX = i;
                startY = j;
            }
        }
    }

    int result = bfs(startX, startY);
    if(result == 0) cout << "TT" << '\n';
    else cout << result << '\n';

    return 0;
}