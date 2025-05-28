#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
int num[1001][1001];
int visited[1001][1001];
int targetX, targetY;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(!visited[nx][ny] && num[nx][ny] != 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> num[i][j];
            if(num[i][j] == 2) {
                targetX = i;
                targetY = j;
            }
        }
    }

    bfs(targetX, targetY);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(num[i][j] == 0) {
                cout << 0 << ' ';
            }
            else {
                cout << visited[i][j] - 1 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}