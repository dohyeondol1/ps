#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool grid[26][26] = { 0, };
bool visited[26][26] = { false, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int dfs(int y, int x) {
    visited[y][x] = true;
    int houseCount = 1;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny > N-1 || nx > N-1) continue;
        if(grid[ny][nx] == 0 || visited[ny][nx]) continue;
        houseCount += dfs(ny, nx);
    }
    
    return houseCount;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < N; j++)
            grid[i][j] = row[j] - '0';
    }
            
    vector<int> answer;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                int cnt = dfs(i, j);
                answer.push_back(cnt);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    cout << answer.size() << '\n';
    for(auto &ans : answer)
        cout << ans << '\n';
    
    return 0;
}