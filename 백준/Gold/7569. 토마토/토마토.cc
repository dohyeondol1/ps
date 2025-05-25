#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dz[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, -1, 1, 0, 0 };
bool visited[101][101][101];
int days[101][101][101];

int bfs(vector<vector<vector<int>>>& box, int H, int N, int M) {
    queue<tuple<int, int, int>> q;

    for(int h = 0; h < H; h++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(box[h][i][j] == 1) {
                    q.push({h, i, j});
                    visited[h][i][j] = true;
                }
            }
        }
    }

    int maxDay = 0;

    while(!q.empty()) {
        auto [z, y, x] = q.front();
        q.pop();

        for(int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nz >= 0 && nz < H && ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if(!visited[nz][ny][nx] && box[nz][ny][nx] == 0) {
                    visited[nz][ny][nx] = true;
                    box[nz][ny][nx] = 1;
                    days[nz][ny][nx] = days[z][y][x] + 1;
                    maxDay = max(maxDay, days[nz][ny][nx]);
                    q.push({nz, ny, nx});
                }
            }
        }
    }

    for(int h = 0; h < H; h++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(box[h][i][j] == 0) return -1;

    return maxDay;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
    for(int h = 0; h < H; h++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                cin >> box[h][i][j];

    cout << bfs(box, H, N, M) << '\n';
    return 0;
}