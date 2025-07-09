#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int board[101][101];
int N, K, L;
int direction = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> K;
    for(int i = 0; i < K; ++i) {
        int row, col;
        cin >> row >> col;
        board[row][col] = 2;
    }
    
    cin >> L;
    queue<pair<int, char>> turns;
    for(int i = 0; i < L; ++i) {
        int t;
        char d;
        cin >> t >> d;
        turns.push({t, d});
    }
    
    int time = 0;
    deque<pair<int, int>> snake;
    snake.push_back({1, 1});
    board[1][1] = 1;
        
    while(true) {
        time++;
        int headY = snake.back().first + dy[direction];
        int headX = snake.back().second + dx[direction];
        
        if(headY <= 0 || headY > N || headX <= 0 || headX > N || board[headY][headX] == 1)
            break;
        
        if(board[headY][headX] != 2) {
            auto tail = snake.front();
            board[tail.first][tail.second] = 0;
            snake.pop_front();
        }
        
        board[headY][headX] = 1;
        snake.push_back({headY, headX});
        
        if(!turns.empty() && time == turns.front().first) {
            char dir = turns.front().second;
            if(dir == 'D')
                direction = (direction + 1) % 4;
            else
                direction = (direction + 3) % 4;
            turns.pop();
        }
    }
    
    cout << time << '\n';
    return 0;
}