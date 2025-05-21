#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
int map[501][501];
int visited[501][501];
int colCheck[501];
int answer[501];
int area = 0;

void dfs(int x, int y) {
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
        if(visited[nx][ny] || map[nx][ny] == 0) continue;

        visited[nx][ny] = 1;
        if(!colCheck[ny]) colCheck[ny] = 1;
        area++;

        dfs(nx, ny);
    }
}

int solution(vector<vector<int>> land) {
    N = land.size();
    M = land[0].size();

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            map[i][j] = land[i - 1][j - 1];

    for(int col = 1; col <= M; col++) {
        for(int row = 1; row <= N; row++) {
            if(map[row][col] == 0 || visited[row][col]) continue;

            visited[row][col] = 1;
            colCheck[col] = 1;
            area = 1;

            dfs(row, col);

            for(int i = 1; i <= M; i++) {
                if(colCheck[i]) {
                    answer[i] += area;
                    colCheck[i] = 0;
                }
            }

            area = 0;
        }
    }

    int maxOil = 0;
    for(int i = 1; i <= M; i++)
        maxOil = max(maxOil, answer[i]);

    return maxOil;
}