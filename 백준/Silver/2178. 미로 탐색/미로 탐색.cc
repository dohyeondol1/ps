#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
int map[100][100];
bool visited[100][100];
int moveCount[100][100];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    moveCount[0][0] = 1;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                continue;

            if(!visited[nextY][nextX] && map[nextY][nextX] == 1) {
                q.push({nextY, nextX});
                visited[nextY][nextX] = true;
                moveCount[nextY][nextX] = moveCount[y][x] + 1;
            }
        }
    }

    return moveCount[N-1][M-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    string mapInputString;
    for(int i = 0; i < N; ++i) {
        cin >> mapInputString;
        for(int j = 0; j < M; ++j) {
            map[i][j] = mapInputString[j] - '0'; 
            visited[i][j] = false;
            moveCount[i][j] = 0;
        }
    }
    
    cout << bfs() << '\n';

    return 0;
}