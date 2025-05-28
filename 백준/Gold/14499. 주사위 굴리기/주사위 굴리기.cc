#include <iostream>
#include <vector>
using namespace std;
 
int dice_top = 0;
int dice_bottom = 0;
int dice_front = 0;
int dice_back = 0;
int dice_left = 0;
int dice_right = 0;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;
    
    vector<vector<int>> grid(N, vector<int> (M));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> grid[i][j];
    
    int order, temp;
    while(K--) {
        cin >> order;
        if(order == 1) {  //동
            if(y+1 > M-1) continue;
            y++;
            //주사위 회전
            temp = dice_right;
            dice_right = dice_top;
            dice_top = dice_left;
            dice_left = dice_bottom;
            dice_bottom = temp;
            
            if(grid[x][y] == 0) grid[x][y] = dice_bottom;
            else {
                dice_bottom = grid[x][y];
                grid[x][y] = 0;
            }
        }
        if(order == 2) {  //서
            if(y-1 < 0) continue;
            y--;
            
            temp = dice_right;
            dice_right = dice_bottom;
            dice_bottom = dice_left;
            dice_left = dice_top;
            dice_top = temp;
            
            if(grid[x][y] == 0) grid[x][y] = dice_bottom;
            else {
                dice_bottom = grid[x][y];
                grid[x][y] = 0;
            }
        }
        if(order == 3) {  //북
            if(x-1 < 0) continue;
            x--;
            
            temp = dice_front;
            dice_front = dice_bottom;
            dice_bottom = dice_back;
            dice_back = dice_top;
            dice_top = temp;
            
            if(grid[x][y] == 0) grid[x][y] = dice_bottom;
            else {
                dice_bottom = grid[x][y];
                grid[x][y] = 0;
            }
        }
        if(order == 4) {  //남
            if(x+1 > N-1) continue;
            x++;
            
            temp = dice_front;
            dice_front = dice_top;
            dice_top = dice_back;
            dice_back = dice_bottom;
            dice_bottom = temp;
            
            if(grid[x][y] == 0) grid[x][y] = dice_bottom;
            else {
                dice_bottom = grid[x][y];
                grid[x][y] = 0;
            }
        }
        cout << dice_top << '\n';
    }
    
    return 0;
}