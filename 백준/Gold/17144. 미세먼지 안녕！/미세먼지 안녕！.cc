#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C, T;
    cin >> R >> C >> T;
    vector<vector<int>> grid(R, vector<int>(C));
    int air1 = -1, air2 = -1;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == -1) {
                if(air1 == -1) air1 = i;
                else air2 = i;
            }
        }
    }

    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {-1, 1, 0, 0};

    while(T--) {
        vector<vector<int>> temp(R, vector<int>(C, 0));
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(grid[i][j] > 0) {
                    int spread_amount = grid[i][j] / 5;
                    int count = 0;
                    for(int d = 0; d < 4; d++) {
                        int ni = i + dy[d];
                        int nj = j + dx[d];
                        if(ni < 0 || nj < 0 || ni >= R || nj >= C) continue;
                        if(grid[ni][nj] == -1) continue;
                        temp[ni][nj] += spread_amount;
                        count++;
                    }
                    temp[i][j] -= spread_amount*count;
                }
            }
        }

        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                grid[i][j] += temp[i][j];

        
        
        // 위쪽
        for(int i = air1 - 1; i > 0; i--)
            grid[i][0] = grid[i-1][0];
        for(int j = 0; j < C-1; j++)
            grid[0][j] = grid[0][j + 1];
        for(int i = 0; i < air1; i++)
            grid[i][C-1] = grid[i+1][C-1];
        for(int j = C-1; j > 1; j--)
            grid[air1][j] = grid[air1][j-1];
        grid[air1][1] = 0;

        // 아래쪽
        for(int i = air2+1; i < R-1; i++)
            grid[i][0] = grid[i + 1][0];
        for(int j = 0; j < C-1; j++)
            grid[R-1][j] = grid[R-1][j+1];
        for(int i = R-1; i > air2; i--)
            grid[i][C-1] = grid[i-1][C-1];
        for(int j = C-1; j > 1; j--)
            grid[air2][j] = grid[air2][j-1];
        grid[air2][1] = 0;
    }

    int answer = 0;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(grid[i][j] > 0) answer += grid[i][j];

    cout << answer << '\n';
    return 0;
}