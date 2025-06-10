#include <vector>
#include <queue>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> board) {
    int N = board.size();
    int visited[25][25][4];
    for(int y = 0; y < N; y++)
        for(int x = 0; x < N; x++)
            for(int d = 0; d < 4; d++)
                visited[y][x][d] = 1e9;

    queue<int> q;
    for(int d = 0; d < 4; d++) {
        visited[0][0][d] = 0;
        q.push(0);
        q.push(0);
        q.push(d);
        q.push(0);
    }

    while(!q.empty()) {
        int y = q.front(); q.pop();
        int x = q.front(); q.pop();
        int dir = q.front(); q.pop();
        int cost = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if(board[ny][nx] == 1) continue;

            int nextCost = cost + 100;
            if(dir != i) nextCost += 500;

            if(visited[ny][nx][i] > nextCost) {
                visited[ny][nx][i] = nextCost;
                q.push(ny);
                q.push(nx);
                q.push(i);
                q.push(nextCost);
            }
        }
    }

    int answer = 1e9;
    for(int d = 0; d < 4; d++)
        if(visited[N-1][N-1][d] < answer) answer = visited[N-1][N-1][d];
    
    return answer;
}