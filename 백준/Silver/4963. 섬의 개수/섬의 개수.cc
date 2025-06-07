#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w, h, cnt;
int visited[51][51] = { false, };
int dy[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dx[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

void dfs(int y, int x, vector<vector<int>> &graph) {
    visited[y][x] = true;

    for(int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny > h-1 || nx > w-1) continue;
        if(!visited[ny][nx] && graph[ny][nx] == 1) dfs(ny, nx, graph);
    } 
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    while(1) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        
        cnt = 0;
        vector<vector<int>> grid(h, vector<int> (w));
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> grid[i][j];
                visited[i][j] = false;
            }
        }
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(!visited[i][j] && grid[i][j]) {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        
        cout << cnt << '\n';
    }

    return 0;
}